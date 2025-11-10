#include <iostream>

template<class T>
void foo(T&& t)
{
    std::cout << "foo" << std::endl;
    boo(std::forward<T&&>(t));
}

template<class T>
void boo(T& t)
{
    std::cout << "boo lvalue" << std::endl;
}

template<class T>
void boo(const T&& t)
{
    std::cout << "boo rvalue" << std::endl;
}

struct A
{
    int a;
    std::string b;
};

int main()
{
    A a;
    foo(a);
    foo(std::move(a));
    return 0;
}

