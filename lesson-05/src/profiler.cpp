
#include <iostream>
#include <chrono>
#include <thread>
#include <source_location>

class Profiler
{
public:
    Profiler(const std::source_location& location = std::source_location::current())
    {
        start_ts_ = std::chrono::system_clock::now();
        location_ = location;
    }
    ~Profiler()
    {
        auto end_ts = std::chrono::system_clock::now();
        uint64_t delta = std::chrono::duration_cast<std::chrono::milliseconds>(end_ts - start_ts_).count();
        std::cout << "Time of execution function '" << location_.function_name() << "' is " << delta << " ms" << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::system_clock> start_ts_;
    std::source_location location_;
};

void foo()
{
    Profiler prf;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

void boo()
{
    Profiler prf;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int main()
{
    foo();
    boo();
}
