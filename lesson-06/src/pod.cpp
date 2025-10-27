#include <iostream>

struct Base
{
    int d;
};

struct POD : Base
{
    POD(int) {}
    int a;
    bool b;
    char c;
};

int main()
{
    std::cout << std::boolalpha << std::is_pod<int32_t>::value << std::endl;
    std::cout << std::boolalpha << std::is_pod<POD>::value << std::endl;
    //POD pod{1, true, 'c'};
    //std::cout << pod.a << " " << pod.b << " " << pod.c << std::endl;
    std::cout << std::boolalpha << std::is_trivial<POD>::value << std::endl;
    std::cout << std::boolalpha << std::is_standard_layout<POD>::value << std::endl;
}
