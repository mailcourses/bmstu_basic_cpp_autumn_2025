#include <iostream>

struct A
{
    void foo(int) const
    {
        std::cout << "A::foo" << std::endl;
    }
};

struct B
{
    void foo() const
    {
        std::cout << "B::foo" << std::endl;
    }
};

struct C
{
};

template<class T>
class has_void_foo
{
public:
    static const bool value = std::is_same<void, decltype(has_void_foo<T>::check(static_cast<T*>(nullptr)))>::value;
private:
    static char check(...); // функция check возвращает любой тип отличный от void

    template<class U>
    static auto check(U* u) -> decltype(u->foo());
};

template<class T>
void optimize(const T& obj,
              typename std::enable_if<has_void_foo<T>::value>::type* = nullptr)
{
    obj.foo();
}

template<class T>
void optimize(const T& obj,
              typename std::enable_if<!has_void_foo<T>::value>::type* = nullptr)
{
    // Что-то долго-долго вычисляем
    std::cout << "very very long executing..." << std::endl;
}

int main()
{
    {
        A a;
        optimize(a);
    }
    {
        B b;
        optimize(b);
    }
    {
        C c;
        optimize(c);
    }
}

