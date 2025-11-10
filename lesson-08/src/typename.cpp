#include <iostream>

struct Array
{
    using const_iterator = int32_t;
    static const int32_t iterator = 100500;
};

template <class Container>
class Parser
{
    typename Container::const_iterator *x; // Ошибка*
};

int main()
{
    int32_t a = Array::iterator;
    Parser<Array> parser;
}
