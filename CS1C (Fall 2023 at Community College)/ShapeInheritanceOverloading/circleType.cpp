#include "circleType.h"


circleType::circleType()
{
    shapeType();
    radius = 0.00;
    setShape("Circle");
}

//If radius is passed in when object is declared, find its area and perimeter
circleType::circleType(double rad)
{
    shapeType();
    radius = rad;
    setPerimeter(2 * 3.14 * radius);
    setArea(3.14 * radius * radius);
    setShape("Circle");
}

double circleType::getRadius() const
{
    return radius;
}

void circleType::setRadius(double r)
{
    //update the circumference and area
    radius = r;
    setPerimeter(2 * 3.14 * radius);
    setArea(3.14 * radius * radius);
}


void circleType::printCircle() const
{
    cout << "----------------------------------------------" << endl;
    cout << "Printing circle:" << endl;
    cout << "Radius: " << radius << endl;
    cout << "Area: " << getArea() << endl;
    cout << "Circumference: " << getPerimeter() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "----------------------------------------------" << endl;
    cout << "End of printCircle function." << endl << endl << endl;

}
