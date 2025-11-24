#include <iostream>
#include <sstream>
#include <map>
#include <unordered_map>

int main()
{
    std::map<std::string, size_t> m = {{"Walter", 0}, {"Jessy", 0}, {"Mike", 0}};
    for (auto& [key, value] : m)
    {
        std::cout << key << ":" << value << std::endl;
    }

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        std::cout << it->first << ":" << it->second << std::endl;
    }

    std::stringstream ss{"word1 word2 word1 word3 word2 word1"};
    std::string str;
    std::unordered_map<std::string, size_t> freq;
    while (ss >> str)
    {
        freq[str] += 1;
    }

    for (auto& [key, value] : freq)
    {
        std::cout << key << ":" << value << std::endl;
    }

    {
        const std::map<std::string, std::vector<size_t>> word_freq;
        std::cout << word_freq.size() << " " << std::boolalpha << word_freq.contains("cat") << " " << word_freq.size() << std::endl;
        auto it = word_freq.find("cat");
        bool has_key = it != word_freq.end();
    }
    return 0;
}
