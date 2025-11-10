#include <iostream>
#include <sstream>

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
concept HasFoo =
    requires(T t) {
        { t.foo() } -> std::same_as<void>;
    };

template<class T>
concept OstreamWrite =
    /*requires(T t) {
        { std::cout << t } -> std::same_as<std::ostream&>;
    };*/
    requires(std::ostream &os, T value) {
        { os << value } -> std::convertible_to<std::ostream &>;
    };

template<HasFoo T>
void optimize(const T& obj)
{
    obj.foo();
}

template<class T>
void optimize(const T& obj)
{
    // Что-то долго-долго вычисляем
    std::cout << "very very long executing..." << std::endl;
}

template<OstreamWrite T>
void write(const T& obj)
{
    std::stringstream ss;
    ss << obj;
    std::cout << ss.str() << std::endl;
}

template<class T>
void write(const T& obj)
{
    std::cout << "Type T has no ostream" << std::endl;
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

    write(C{});
    write("hello");
}

