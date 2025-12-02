#include <queue>
#include <thread>
#include <iostream>

using client_t = size_t;

std::queue<client_t> clients;

class Barbershop
{
public:
    Barbershop(size_t max_chairs) : max_chairs_(max_chairs) {}
    void push_client(size_t id)
    {
        std::unique_lock<std::mutex> lock_;
        if (clients.size() == max_chairs_)
        {
            std::cout << "Client{" << id << "} is going out...\n";
            return;
        }
        clients.push(id);
        std::cout << "Client{" << id << "} is pushing to queue...\n";
        cv_.notify_one();
    }

    void work()
    {
        while(true)
        {
            std::unique_lock<std::mutex> lock(mutex_);
            if (!clients.empty())
            {
                auto client = clients.front();
                clients.pop();
                std::cout << "Barber is triming client{" << client << "}\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            else
            {
                std::cout << "Barber is sleeping..." << std::endl;
                cv_.wait(lock);
            }
        }
    }
private:
    size_t max_chairs_{0};
    std::mutex mutex_;
    std::condition_variable cv_;
};

int main()
{
    Barbershop barber{3};
    std::vector<std::thread> threads;
    threads.emplace_back([&barber](){
        barber.work();
    });

    for (size_t i = 0; i < 10; ++i)
    {
        threads.emplace_back([&barber, i](){
            barber.push_client(i);
        });
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    for (auto& thread : threads)
    {
        thread.join();
    }
    return 0;
}

