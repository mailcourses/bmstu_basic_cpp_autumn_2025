#include <iostream>

struct A
{
// A() = default;
protected:
    int getC() const
    {
        return c;
    }
public:
    int a{1};
protected:
    int b{2};
private:
    int c{3};
};

struct B: private A
{
// B() = default;
public:
    int sum()
    {
        return a + b + getC();
    }
};

int main()
{
    B* b = new B;
    std::cout << b->sum() << std::endl;
    //A* a = static_cast<A*>(b);
    //std::cout << "A.a = " << a->a << std::endl;
    return 0;
}
