#include <iostream>
#include "Triangle.h"

int main() {


    // Create a triangle with specified sides
    Triangle driehoek(3.0, 4.0, 5.0);
    std::cout << "Custom Triangle:" << std::endl;
    std::cout << "Side 1: " << driehoek.getSide1() << std::endl;
    std::cout << "Side 2: " << driehoek.getSide2() << std::endl;
    std::cout << "Side 3: " << driehoek.getSide3() << std::endl;
    std::cout << "Area: " << driehoek.getArea() << std::endl;
    std::cout << "Perimeter: " << driehoek.getPerimeter() << std::endl;

    return 0;
}