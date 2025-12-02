#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

std::atomic<int32_t> i = 0;

void plus1()
{
    i += 1;
}

int main()
{
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 2048; ++i)
    {
        threads.emplace_back(plus1);
    }
    for (auto& thread : threads)
    {
        thread.join();
    }
    std::cout << "i = " << i << std::endl;
}
