#include <iostream>
#include <cstdint>
#include <string>

class Dachshund
{
public:
    Dachshund() { age_ = 0; }
    // Конструктор
    Dachshund(uint8_t age) { age_ = age; }
    // Деструктор
    ~Dachshund() {}
public:
    std::string name = "default"; // публичный член класса
protected:
    float weight_ = 0.0f; // защищённый член класса
private:
    uint8_t age_ = 0; // закрытый член класса
};

class LittleDachshund : public Dachshund
{
public:
    LittleDachshund()
    {
        //age_ = 100;
        weight_ = 10;
        name = "Roksy";
    }
};

struct Animal
{
    Animal(uint32_t id) : id_(id)
    {
    }
    uint32_t id_;
};

struct Logger
{
    void print(const std::string& name)
    {
        std::cout << "INFO: " << name << std::endl;
    }
};

struct Ape : Animal
{

    using age_type = uint8_t;

    Ape(std::string& name) : Animal(12345), name_(name), age_(14)
    {
    }

    void voice() const
    {
        //...
        logger.print("Aaaaaaaa");
    }

    void eat()
    {
    }

    // ++i
    age_type operator++()
    {
        ++age_;
        return age_;
    }

    // i++
    age_type operator++(int)
    {
        age_type tmp = age_;
        ++age_;
        return tmp;
    }

    void operator+(/* A* this,*/ age_type inc)
    {
        age_ += inc;
    }

    friend std::ostream& operator<<(std::ostream& os, const Ape& ape);

    std::string& name_;
    mutable Logger logger;
private:
    age_type age_;
};

void operator+(Ape::age_type inc, Ape& ape)
{
    ape + inc;
}

std::ostream& operator<<(std::ostream& os, const Ape& ape)
{
    os << "Ape, age=" << ape.age_ << ", name=" << ape.name_;
    return os;
}

int main()
{
    Dachshund roksana{8};// <-- пользовательский конструктор
    Dachshund shokolad; // <-- конструктор по умолчанию
    /*shokolad.age_;
    shokolad.weight_;*/
    auto b = shokolad.name;

    std::string ape_name{"Ceaser"};
    const Ape ceaser(ape_name);
    ceaser.voice();
    Ape rocket(ape_name);
    rocket++;
    ++rocket;
    rocket.operator++(10);
    //rocket + ceaser;
    rocket + 20;
    20 + rocket;
    //rocket << std::cout << std::endl;
    std::cout << rocket << std::endl;
    //ceaser.eat();
}
