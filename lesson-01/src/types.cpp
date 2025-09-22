#include <stdio.h>
#include <string>

void f(float)
{
    printf("f( float )");
}

void f(double)
{
    printf("f( double )");
}

void f(long double)
{
    printf("f( long double )\n");
}

int main()
{
    f(1.1l);
    std::string s1{"abc"};
    std::string s2{"def"};
    std::string s3 = s1 + s2; // s1.operator+(s2);
    s1.resize(100);
    printf("new string is [%s] s3.size = %zu, s1.size = %zu", s3.c_str(), s3.size(), s1.size());
}
