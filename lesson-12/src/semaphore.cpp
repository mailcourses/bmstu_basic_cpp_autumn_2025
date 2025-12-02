#include <semaphore>
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

std::counting_semaphore<2> semaphore{2};

void foo(size_t id)
{
    std::cout << "Starting id{" << id << "} thread" << std::endl;
    semaphore.acquire();
    std::cout << "id{" << id << "} executing...."  << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    semaphore.release();
    std::cout << "Ending id{" << id << "} thread" << std::endl;
}

int main()
{
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 5; ++i)
    {
        threads.emplace_back(foo, i);
    }

    for (auto& thread : threads)
    {
        thread.join();
    }
    return 0;
}

