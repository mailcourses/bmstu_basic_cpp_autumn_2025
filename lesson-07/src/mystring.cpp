#include <iostream>
#include <cstring>

namespace my
{

class string
{
public:
    explicit string(const char* str) : size_(strlen(str)), data_(new char[size_])
    {
        for (size_t i = 0; i < size_; ++i)
        {
            data_[i] = str[i];
        }
    }

    string(const string& rhs) = default; // size_(rhs.size_), data_(rhs.data_)

    ~string()
    {
        delete[] data_;
    }
private:
    size_t size_ = 0;
public:
    char *data_ = nullptr;
};

} // namespace my

int main()
{
    my::string str1{"hello kitty"};
    //Не скомпилируется из-за explicit!
    //my::string str2 = "hello kitty";
    std::cout << std::string{str1.data_} << std::endl;
    {
        // Двойное очищение памяти из-за конструктора копирования.
        my::string str2{str1};
    }
}
