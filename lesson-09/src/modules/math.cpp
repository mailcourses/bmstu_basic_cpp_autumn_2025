module;

#include <iostream>

export module math;

export int32_t square(int32_t num)
{
    return num * num;
}

export namespace search
{
    void foo() {}
    void boo() {}
}

void unexported()
{
    std::cout << "unexported" << std::endl;
}

export
{
    void dummy()
    {
        unexported();
    }
};
