#include "shapeType.h"
#include "triangleType.h"

triangleType::triangleType()
{
    shapeType();
    base = 0.00;
    height = 0.00;
    setShape("Triangle");
}


triangleType::triangleType(double b, double h)
{
    shapeType();
    base = b;
    height = h;
    setArea(base * height * 0.5);
    hypotenuse = sqrt((base * base) + (height * height));
    setPerimeter(base + height + hypotenuse);
    setShape("Triangle");
}


void triangleType::setBase(double newB)
{
    base = newB;
    setArea(base * height * 0.5);
    hypotenuse = sqrt((base * base) + (height * height));
    setPerimeter(base + height + hypotenuse);
}


void triangleType::setHeight(double newH)
{
    height = newH;
    setArea(base * height * 0.5);
    hypotenuse = sqrt((base * base) + (height * height));
    setPerimeter(base + height + hypotenuse);
}


double triangleType::getBase() const
{
    return base;
}


double triangleType::getHeight() const
{
    return height;
}


void triangleType::printTriangle() const
{
     cout << "----------------------------------------------" << endl;
     cout << "Printing triangle: " << endl;
     cout << "Base: " << base << endl;
     cout << "Height: " << height << endl;
     cout << "Triangle area: " << getArea() << endl;
     cout << "Triangle perimeter: " << getPerimeter() << endl;
     cout << "Triangle color: " << getColor() << endl;
     cout << "----------------------------------------------" << endl;
     cout << "End of printTriangle function." << endl << endl << endl;
}
