#include <iostream>

template<class T>
void print(T&& value)
{
    std::cout << value << '\n';
}

template<class T, class... Args>
void print(T&& value, Args&&... args)
{
    std::cout << value << std::endl;
    print(std::forward<Args>(args)...);
}

int main()
{
    print(1, "Hello", 5.0f, true, 'z');
}
