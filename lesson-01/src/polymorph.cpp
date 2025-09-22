#include <stdio.h>

struct Animal
{
    virtual void voice() { printf("Animal::voice\n"); }
};

struct Dog : Animal
{
    void voice() override { printf("Dog::voice\n"); }
};

void make_voice(Animal& obj)
{
    obj.voice();
}

int main()
{
    int i;
    Animal animal;
    make_voice( animal );
    Dog dog;
    make_voice( dog );
}
