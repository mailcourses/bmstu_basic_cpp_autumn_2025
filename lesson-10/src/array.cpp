#include <iostream>
#include <array>

/*
 * Пример, как мог бы быт реализован метод at.
class array
{
public:
    const T& at(size_t i)
    {
        if (i > size_)
            throw std::out_of_range("");
        return data_[i];
    }
private:
    size_t size_;
}*/

int main()
{
    std::array<int, 3> arr = {1, 2, 3};
    const size_t i = 10;
    //std::cout << arr[i] << std::endl;   <-- не ок, но может быть выполнится
    //std::cout << arr.at(i) << std::endl;<-- ок, но может быть кинет исключение

    // arr = {1,2,3}
    // [1][2][3][.][.][.][.][.]
    //  |     |
    //  p1    p2
    int* p1 = arr.data();
    std::cout << *p1 << std::endl;
    int* p2 = p1 + 2;
    std::cout << *p2 << std::endl;
    std::cout << *(p1+1) << std::endl;

    {
        std::array<int, 1024> arr2;
        const size_t n = arr2.size();
        for (size_t i = 0; i < n; ++i)
            arr2[i] = i;
        int* p3 = arr2.data();
        std::cout << *(p3 + n / 2) << std::endl;
    }
    return 0;
}

