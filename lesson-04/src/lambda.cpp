#include <vector>
#include <algorithm>

void foo()
{
    std::vector<int> arr = {1, 4, 5};
    int i = 5;
    auto it = std::begin(arr);
    std::vector<int>::iterator it2 = std::begin(arr);

    int divider = 5;
    auto comp = [&divider](int i) { return i % divider == 0; };
    std::find_if(std::begin(arr), std::end(arr), comp);
}
