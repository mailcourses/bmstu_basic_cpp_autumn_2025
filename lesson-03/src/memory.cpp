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

int main()
{
    for (size_t i = 0; i < 5; ++i)
    {
        int res = foo(i);
        std::cout << "j=" << res << ", i=" << statici << std::endl;
    }

    std::string* str = (std::string*)malloc(sizeof(std::string));
    str->push_back('a');
}

