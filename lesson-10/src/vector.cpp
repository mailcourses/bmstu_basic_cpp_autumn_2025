#include <iostream>
#include <vector>
#include <array>
#include <list>

template<class T>
class vector
{
public:
    using value_type = T;
    using size_type = size_t;
public:
    vector() = default;
    vector(size_type size, value_type init) : size_(size), capacity_(size_)
    {
        data_ = new T[size];
        for (size_t i = 0; i < size_; ++i)
        {
            data_[i] = init;
        }
    }
    /*
     * [][][]
     */
    void push_back(const T& rhs)
    {
        if (size_ == capacity_)
        {
            capacity_ = size_ * 2;
            T* tmp = new T[capacity_];
            for (size_t i = 0; i < size_; ++i)
            {
                tmp[i] = data_[i];
            }
            delete[] data_;
            data_ = tmp;
        }
        data_[size_] = rhs;
        size_ += 1;
    }

    ~vector()
    {
        delete[] data_;
    }
private:
    value_type* data_{nullptr};
    size_type size_{0};
    size_type capacity_{0};
};

template<class C>
void print_container(const C& container)
{
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

struct A
{
    A(int32_t, const std::string& )
    {
    }
};

int main()
{
    {
        vector<int32_t> v(5, 0);
        // 1 + 2 + 4 + 8 + 16 + ... n / 2 + n
        // O(n + n/2 + n/4 + ...) = n(1+1/2+1/4+...) = O(2n) = O(n)
        for (size_t i = 0; i < 10; ++i)
        {
            v.push_back(10 + i);
        }
    }

    {
        std::vector<int32_t> v = {1, 2, 3, 4, 5, 6, 7};
        /*
        std::vector<int32_t>::reverse_iterator it = v.rbegin();
        std::vector<int32_t>::reverse_iterator it_end = v.rend();
        for (; it != it_end; ++it)
        {
            std::cout << *it << std::endl;
        }
        */
        print_container(v);

        std::array<std::string, 3> arr = {"hello", "world", "kitty"};
        print_container(arr);

        std::list<double> l = {3.1415, 2.71, 1.618};
        print_container(l);
    }

    {
        std::vector<int32_t> v = {1, 2, 3, 4, 5, 6, 7};
        auto it = v.begin() + v.size() / 2;
        std::cout << *it << std::endl;
        std::cout << v.size() << " -> " << v.capacity() << std::endl;
        const size_t n = v.size();
        for (size_t i = 0; i < n; ++i)
        {
            v.push_back(v[i]);
            std::cout << "  " <<  v.size() << " -> " << v.capacity() << std::endl;
        }
        std::cout << v.size() << " -> " << v.capacity() << std::endl;
        std::cout << *it << std::endl;

        const size_t n2 = v.size() - 2;
        for (size_t i = 0; i < n2; ++i)
        {
            v.pop_back();
            std::cout << "  " <<  v.size() << " -> " << v.capacity() << std::endl;
        }
        v.clear();
        //std::vector<int32_t>().swap(v);
        std::cout <<  v.size() << " -> " << v.capacity() << std::endl;
        v.push_back(1);
        v.push_back(2);
        std::cout <<  v.size() << " -> " << v.capacity() << std::endl;
        v.shrink_to_fit();
        std::cout <<  v.size() << " -> " << v.capacity() << std::endl;
    }

    {
        std::vector<int32_t> v1(100, 0);
        std::cout << v1.size() << " -> " << v1.capacity() << std::endl;
        v1[50] = 100500;

        std::vector<int32_t> v2;
        v2.reserve(100);
        std::cout << v2.size() << " -> " << v2.capacity() << std::endl;
        //v2.at(40);
    }

    {
        std::vector<A> v;
        v.push_back(A(10, "Hello"));
        v.emplace_back(11, "world");
    }
}
