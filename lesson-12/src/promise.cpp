#include <thread>
#include <future>
#include <chrono>
#include <iostream>

int main()
{
    auto task = [](std::future<int32_t> f) {
        std::cout << "task starting..." << std::endl;
        std::cout << f.get() << std::endl;
        std::cout << "task ending..." << std::endl;
    };

    std::promise<int32_t> p;
    std::thread thread(task, p.get_future());
    std::cout << "Waitinig 2 seconds before future get" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    p.set_value(500100);
    std::cout << "End of main thread" << std::endl;
    thread.join();

    return 0;
}

