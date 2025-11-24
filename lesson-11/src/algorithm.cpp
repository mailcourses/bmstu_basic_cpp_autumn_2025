#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> randomNumbers;
    auto iter = std::back_inserter(randomNumbers);
    std::generate_n(iter, 10, std::rand);

    std::copy(std::begin(randomNumbers), std::end(randomNumbers), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}

