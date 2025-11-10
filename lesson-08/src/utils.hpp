#include <cstddef>

template<class T>
class vector
{
public:
    vector() = default;
    void push_back(const T& value);
private:
    T* data_;
    size_t size_;
    size_t capacity_;
};

#include "utils.tpp"
