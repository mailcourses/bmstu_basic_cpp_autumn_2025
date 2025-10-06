
[[gnu::fastcall]]
void foo1(int a, int b, int c, int d, int e, int f, int g, double h)
{
}

void boo1()
{
    foo1(1, 2, 3, 4, 5, 6, 7, 1.9);
}

void foo2(int a, int b, int c, int d, int e, int f, int g, double h)
{
}

void boo2()
{
    foo2(1, 2, 3, 4, 5, 6, 7, 1.9);
}
