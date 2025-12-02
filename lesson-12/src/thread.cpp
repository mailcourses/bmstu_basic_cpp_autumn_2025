#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include <ctime>

void foo(size_t tid)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(tid * 100));
    std::thread::id thread_id = std::this_thread::get_id();
    std::cout << tid << ":" << thread_id << std::endl;
}

std::vector<size_t> result;

void calculate_sum(size_t bucket_id, int* begin, int* end)
{
    size_t sum = 0;
    while (begin != end)
    {
        sum += *begin;
        ++begin;
    }
    result[bucket_id] = sum;
}

int main()
{
    const uint32_t optimal_threads_cnt = std::thread::hardware_concurrency();
    std::cout << "Optimal threads cnt is " << optimal_threads_cnt << std::endl;

    std::vector<int32_t> nums(240);
    std::srand(std::time({}));
    //std::for_each(std::begin(nums), std::end(nums), std::rand);
    for (size_t i = 0; i < nums.size(); ++i)
    {
        nums[i] = std::rand() % 10;
    }
    size_t expected = std::accumulate(std::begin(nums), std::end(nums), 0);
    //std::fill(std::begin(nums), std::end(nums), std::rand());
    for (auto num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    result.resize(optimal_threads_cnt);
    const size_t num_cnt = nums.size();
    std::vector<std::thread> threads;
    size_t share = nums.size() / optimal_threads_cnt;
    std::cout << "share: " << share << std::endl;
    for (size_t i = 0; i < optimal_threads_cnt; ++i)
    {
        int32_t* begin = nums.data() + i * share;
        int32_t* end = nums.data() + (i+1) * share;
        std::thread thread(calculate_sum, i, begin, end);
        threads.push_back(std::move(thread));
    }

    for (auto& thread : threads)
    {
        thread.join();
    }

    size_t actual = std::accumulate(std::begin(result), std::end(result), 0);
    std::cout << "actual: " << actual << ", expected: " << expected << std::endl;

    return 0;
}
