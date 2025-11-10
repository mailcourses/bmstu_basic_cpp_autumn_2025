#include <iostream>

enum class NodeColor
{
    RED,
    BLACK,
    UNKNOWN
};

enum class HttpCode
{
    NotFound = 404,
    Ok = 200,
    InternalServerError = 500,
};

enum class CatColor
{
    WHITE,
    BLACK,
    RED,
    UNKNOWN
};

union Jack
{
    char ch;
    bool flag;
    uint32_t num;
    size_t size;
};

int main()
{
    NodeColor node_color = NodeColor::RED;
    CatColor cat_color = CatColor::RED;

    Jack tmp;
    tmp.flag = true;
    std::cout << std::boolalpha << tmp.flag << std::endl;
    tmp.num = 0;
    std::cout << tmp.flag << std::endl;
    std::cout << tmp.num << std::endl;
    tmp.size = 100500;
    std::cout << tmp.flag << std::endl;
    std::cout << tmp.num << std::endl;
    std::cout << tmp.size << std::endl;
}
