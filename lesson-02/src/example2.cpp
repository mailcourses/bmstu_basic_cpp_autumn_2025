
const int g = 100500;
int a = 10;
int b;

static int c = 10;

void foo()
{
    int magic = 100;
    return;
}

void foo(int i)
{
    static int smagic = 100;
    return;
}

namespace ai
{
    void foo()
    {
        static int smagic = 100;
        return;
    }
}
