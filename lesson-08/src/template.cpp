#include <iostream>

template<class T>
void printLine(const T& value)
{
    std::cout << value << std::endl;
}

class UserType
{
public:
    UserType() = default;
};

template<class T>
class Matrix
{
public:
    Matrix() = default;
    void foo() {}
private:
    T* data;
};

int main()
{
    printLine(5);
    printLine("Hello, world!");
    // printLine(UserType{}); <-- CE

    Matrix<double> m1;
    m1.foo();
    Matrix<std::string> m2;
    m2.foo();
    return 0;
}

