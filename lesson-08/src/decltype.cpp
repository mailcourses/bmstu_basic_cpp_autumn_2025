#include <iostream>
#include <vector>
#include <string>

template<class C, class I>
auto authAndAccess(const C& container, I index) -> decltype(container[index])
{
    //...
    return container[index];
}

int main()
{
    std::vector<std::string> v(11, "100500");
    std::cout << authAndAccess(v, 10) << std::endl;
}
