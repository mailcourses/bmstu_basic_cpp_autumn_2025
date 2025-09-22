#include <iostream> // вместо stdio.h
#include <iomanip> // для std::setw

//using namespace std;

int main()
{
    std::string s1{"Hello world!"};
    std::cout << s1 << "\n";
    //operator<<(operator<<(std::cout, s1), "\n");
    int d;
    char c;
    //scanf("%d %c", &d, &c);
    std::cin >> d >> c; // operator>>(std::cin, d)
    std::cout << "d = " << d << ", c = " << c << "\n" << std::endl;
    std::cout << std::setw(20) << std::setfill('#');
    std::cout << s1 << "\n";
    bool b = true;
    std::cout << std::boolalpha << b << std::endl;
}
