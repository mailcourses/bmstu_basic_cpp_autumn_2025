#include <queue>
#include <vector>
#include <iostream>

constexpr uint32_t K = 3;

struct Foo
{
    std::string name;
    uint32_t age;
    uint32_t social_rank;
};

std::ostream& operator<<(std::ostream& os, const Foo& rhs)
{
    os << "Foo(" << rhs.name << ", " << rhs.age << ", " << rhs.social_rank << ")";
    return os;
}

int main()
{
    std::vector<int32_t> v1 = {10, 4, 7, 1, 5, 6, 2};
    {
        auto v2 = v1;
        // O(n log n + K) -> O(n log n)
        std::sort(std::begin(v2), std::end(v2), std::greater<int32_t>());
        for (size_t i = 0; i < K; ++i)
        {
            std::cout << v2[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << " =============== " << std::endl;
    {
        auto v2 = v1;
        // O(n log K)
        std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>> pq( std::greater<int32_t>{} );
        for (size_t i = 0; i < v2.size(); ++i)
        {
            pq.push( v2[i] );
            if (pq.size() > K)
            {
                pq.pop();
            }
        }

        std::vector<int32_t> res;
        while (!pq.empty())
        {
            auto top = pq.top();
            res.push_back(top);
            pq.pop();
//            std::cout << top << " ";
        }
        reverse(std::begin(res), std::end(res));
        for (auto elem: res)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    {
        std::vector<Foo> v2 = {Foo{"Walter White", 52, 10}, Foo{"Jesse Pinkman", 25, 5}, Foo{"Saul Goodman", 45, 7}, Foo{"Mike Ermentraute", 65, 10}, Foo{"Saul Foodman", 45, 7}};

        auto comp = [](const Foo& lhs, const Foo& rhs) {
            return std::tie(lhs.social_rank, lhs.age, lhs.name) < std::tie(rhs.social_rank, rhs.age, rhs.name);
            if (lhs.social_rank < rhs.social_rank)
                return true;
            else if(lhs.age < rhs.age)
                return true;
            return lhs.name < rhs.name;
        };
        std::priority_queue<Foo, std::vector<Foo>, decltype(comp)> pq(std::begin(v2), std::end(v2), comp);
        while (!pq.empty())
        {
            auto top = pq.top();
            std::cout << top << std::endl;
            pq.pop();
        }
    }

    return 0;
}

