
void foo(int)
{
}

void foo(int&)
{
}

void foo(int*)
{
}

void foo(const int&)
{
}

int main()
{
    //foo(100);
    int a = 10;
    //foo(a);
}
