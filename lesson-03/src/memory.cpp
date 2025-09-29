#include <iostream>
#include <cstddef>

int globali = 100500;
int globalj;

static int statici = 0;

int foo(int num)
{
    static int staticj = 0;
    staticj += num;
    statici += num;
    return staticj;
}

/*
 * class string {
 *   size_t size_;
 *   size_t capacity_;
 *   char* data_;
 * }
 */

int main()
{
    for (size_t i = 0; i < 5; ++i)
    {
        int res = foo(i);
        std::cout << "j=" << res << ", i=" << statici << std::endl;
    }

    //std::string* str = (std::string*)malloc(sizeof(std::string));
    std::string* str = new std::string;
    str->push_back('a');
    std::cout << "str: " << str << std::endl;
    int* a = new int{100500};
    std::cout << "address of a is " << a << std::endl;

    const int * const pointer = new int{500100};
    //pointer = a;
    //*pointer = 5;

    int& magic = globali;
    std::cout << globali << " === " << magic << std::endl;
    magic = -10;
    std::cout << globali << " === " << magic << std::endl;
}

