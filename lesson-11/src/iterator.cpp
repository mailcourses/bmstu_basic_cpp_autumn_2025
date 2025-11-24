#include <iostream>
//#include <initializer_list>
#include <iterator>
#include <numeric>
#include <cstddef>

template<class T>
class Iterator //: public std::iterator<std::forward_iterator_tag, T>
{
public:
    //using iterator_category = std::forward_iterator_tag;
    using iterator_category = std::random_access_iterator_tag;
    using reference = T&;
    using pointer = T*;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
public:
    Iterator(T* ptr) : ptr_(ptr) {}

    bool operator==(const Iterator& rhs)
    {
        return ptr_ == rhs.ptr_;
    }

    bool operator!=(const Iterator& rhs)
    {
        return !(*this == rhs);
    }

    reference operator*()
    {
        return *ptr_;
    }

    pointer operator-(size_t num)
    {
        return ptr_ - num;
    }

    bool operator>=(const Iterator& rhs)
    {
        return *ptr_ >= *rhs.ptr_;
    }

    bool operator<(const Iterator& rhs)
    {
        return *ptr_ < *rhs.ptr_;
    }

    difference_type operator-(const Iterator& rhs)
    {
        return ptr_ - rhs.ptr_;
    }

    /*difference_type operator+(const Iterator& rhs)
    {
        return ptr_ + rhs.ptr_;
    }*/

    pointer operator+(size_t num)
    {
        return ptr_ - num;
    }

    Iterator& operator++()
    {
        ptr_ += 1;
        return *this;
    }

    Iterator& operator--()
    {
        ptr_ -= 1;
        return *this;
    }

private:
    T* ptr_{nullptr};
};

template<class T, size_t size>
class array
{
public:
    using iterator = Iterator<T>;
public:
    array(std::initializer_list<T> init)
    {
        auto it = init.begin();
        const auto end = init.end();
        for (size_t i = 0; it < end; ++it, ++i)
        {
            data_[i] = *it;
        }
    }

    const T& operator[](size_t i)
    {
        return data_[i];
    }

    iterator begin()
    {
        return Iterator(data_);
    }

    iterator end()
    {
        return Iterator(data_ + size_);
    }

private:
    T data_[size];
    size_t size_{size};
};

int main()
{
    array<int32_t, 4> arr1 = {10, 4, 2, 7};
    auto sum = std::accumulate(std::begin(arr1), std::end(arr1), 0);
    std::cout << "sum: " << sum << std::endl;
    std::sort(std::begin(arr1), std::end(arr1));
    return 0;
}

