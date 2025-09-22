#include <iostream>
#include <cassert> // для assert

std::string convert(const std::string& str)
{
    std::string res;
    for (char ch : str)
    {
        res += std::toupper(ch);
    }
    return res;
}

int main()
{
    std::string s1{"Hello world!"};
    std::string actual = convert(s1);
    assert(actual == "HELLO WORLD!");
    //...
    /*if (actual != "HELLO WORLD")
    {
        std::cout << "ERROR!!! Hello kitty" << std::endl;
    }*/

    std::cout << "OK" << std::endl;
}
