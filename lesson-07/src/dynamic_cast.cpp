#include <iostream>
#include <vector>

struct A
{
    virtual void foo() {}
};

struct B : A
{
    void boo ()
    {
        std::cout << "B::boo " << arr.size() << std::endl;
    }
    std::vector<int32_t> arr;
};

struct C : A
{
    void foo() override
    {
        std::cout << "C::foo " << str.size() << std::endl;
    }
    std::string str;
};

int mock(A* a)
{
    B* b = static_cast<B*>(a);
    if (b != nullptr) {
        b->boo();
    }
    else {
        a->foo();
    }
    return 0;
}

int main()
{
    mock(new B);
    mock(new C);
    mock(new A);
}
