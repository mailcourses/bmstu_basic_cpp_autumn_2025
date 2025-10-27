#include <iostream>

class FakeFigure
{
public:
    FakeFigure() = default;
    size_t square()
    {
        std::cout << "FakeFigure::square" << std::endl;
        return 0;
    }
    void draw()
    {
        std::cout << "FakeFigure::draw" << std::endl;
    }
};

class Figure
{
public:
    Figure()
    {
        std::cout << "Figure::ctr" << std::endl;
    }

    virtual size_t square() = 0;

    void draw()
    {
        std::cout << "Figure::draw" << std::endl;
    }

    virtual ~Figure()
    {
        std::cout << "Figure::dctr" << std::endl;
    }
};

class Circle : public Figure
{
public:
    Circle()
    {
        std::cout << "Circle::ctr" << std::endl;
    }

    size_t square() override
    {
        std::cout << "Circle::square" << std::endl;
        return 0;
    }

    ~Circle()
    {
        std::cout << "Circle::dctr" << std::endl;
    }
private:
    size_t radius_{0};
};

class Triangle : public Figure
{
public:
    Triangle() = default;

    size_t square() override
    {
        std::cout << "Triangle::square" << std::endl;
        return 0;
    }
private:
    size_t a{0};
    size_t b{0};
    size_t c{0};
};

Figure* figureFactory(const std::string& figure_name)
{
    if (figure_name == "triangle")
    {
        return new Triangle;
    }
    else if (figure_name == "circle")
    {
        return new Circle;
    }
    return nullptr;
}

void execute(Figure* figure)
{
    if (!figure)
        return;

    figure->draw();
    figure->square();
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <triangle|circle>" << std::endl;
        return 1;
    }
    std::string figure_name = argv[1];
    Figure* figure = figureFactory(figure_name);

    execute(figure);

    std::cout << sizeof(Figure) << std::endl;
    std::cout << sizeof(FakeFigure) << std::endl;

    delete figure;

    Circle *circle = new Circle;
    delete circle;

    return 0;
}

