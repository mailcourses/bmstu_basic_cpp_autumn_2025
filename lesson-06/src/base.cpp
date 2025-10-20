#include <iostream>

struct A
{
    int a{1};
};

struct B : public A
{
    int b{2};
};

struct C : public A
{
    std::string c{"hello"};
};

int main()
{
    B* b = new B;
    A* a = b;
    std::cout << "b->b=" << b->b << std::endl;
    //std::cout << "a->b=" << a->b << std::endl;
    C* c = static_cast<C*>(a);
    std::cout << "c->c=" << c->c << std::endl;
}
