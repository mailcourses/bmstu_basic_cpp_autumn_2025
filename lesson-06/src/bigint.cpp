#include <cstddef>
#include <iostream>
#include <vector>

namespace bigint
{

class Integer
{
    static uint8_t BASE = 10;
public:
    Integer(const std::string& str)
    {
        // 987 + 123 -> {7, 8, 9} + {3, 2, 1}
        data_.reserve(str.size());
        for(int32_t i = str.size()-1; i >= 0; --i)
        {
            data_.push_back(str[i]-'0');
        }
    }

    Integer() = default;

    Integer operator+(/*Integer* this,*/const Integer& rhs) const
    {
        Integer tmp;
        size_t n = std::max(data_.size(), rhs.data_.size());
        tmp.data_.reserve(n + 1);
        size_t k = 0;
        for (size_t i = 0; i < n; ++i)
        {
            size_t left = data_.size() < i ? 0 : data_[i];
            size_t right = rhs.data_.size() < i ? 0 : rhs.data_[i];
            size_t r = (left + right + k) % BASE;
            k = (left + right + k) / BASE;
            tmp.data_.push_back(r);
        }
        if (k != 0)
            tmp.data_.push_back(k);

        return tmp;
    }
    friend std::ostream& operator<<(std::ostream& os, const Integer& rhs);
private:
    std::vector<uint8_t> data_;
};

std::ostream& operator<<(std::ostream& os, const Integer& rhs)
{
    for(int32_t i = rhs.data_.size()-1; i >= 0; --i)
    {
        os << static_cast<char>(rhs.data_[i]+'0');
    }
    return os;
}

};

int main()
{
    {
        bigint::Integer int1{"123"};
        bigint::Integer int2{"456"};
        std::cout << int1 << " + " << int2 << " = " << int1+int2 << std::endl; // int1.add(int2)
    }
    {
        bigint::Integer int1{"999"};
        bigint::Integer int2{"123"};
        std::cout << int1 << " + " << int2 << " = " << int1+int2 << std::endl; // int1.add(int2)
    }
    return 0;
}
