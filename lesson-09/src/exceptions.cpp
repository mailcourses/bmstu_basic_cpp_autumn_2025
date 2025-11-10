#include <iostream>

struct A
{
    A()
    {
        std::cout << "A()" << std::endl;
    }
    ~A()
    {
        std::cout << "~A()" << std::endl;
    }
};

void foo()
{
    A a2;
    throw 10;
}

void boo()
{
    A a1;
    try {
        A a3;
        foo();
    }
    catch(std::exception) { }
    catch(int)
    {
    }
}

struct B
{
    B() : data(new int[1024])
    {
        std::cout << "B()" << std::endl;
        try {
            throw 10;
        } catch (int)
        {
        }
    }
    ~B() noexcept(false)
    {
        //throw 10; <-- явное исключение
        //new int[1000000000000]; <-- неявное исключение std::bad_alloc
        std::cout << "~B()" << std::endl;
        delete[] data;
    }
    int* data;
};

int main()
{
    boo();
    try
    {
        B b;
    } catch (int)
    {
    }
    catch (std::bad_alloc)
    {
    }
}
