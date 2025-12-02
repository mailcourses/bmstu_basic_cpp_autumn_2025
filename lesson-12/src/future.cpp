#include <future>
#include <iostream>
#include <chrono>

int32_t foo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(3500));
    return 100500;
}


int main()
{
    std::future<int32_t> future = std::async(std::launch::async, [](){
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        return 100500;
    });
    while (future.wait_for(std::chrono::milliseconds(500)) != std::future_status::ready)
    {
        std::cout << "Still not ready. Waiting another 500 ms..." << std::endl;
    }
    std::cout << future.get() << std::endl;
    return 0;
}
