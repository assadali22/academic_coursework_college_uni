#include "shapeType.h"
#include "squareType.h"

squareType::squareType()
{
    shapeType();
    side = 0.00;
    setShape("Square");

}

squareType::squareType(double s)
{
    shapeType();
    side = s;
    setArea(side * side);
    setPerimeter(4 * side);
    setShape("Square");

}


void squareType::setSide(double newSide)
{
    side = newSide;
    setArea(side * side);
    setPerimeter(4 * side);
}



double squareType::getSide() const
{
    return side;
}



void squareType::printSquare() const
{
    cout << "----------------------------------------------" << endl;
    cout << "Printing square: " << endl;
    cout << "Square side length: " << side << endl;
    cout << "Square area: " << getArea() << endl;
    cout << "Square perimeter: " << getPerimeter() << endl;
    cout << "Square color: " << getColor() << endl;
    cout << "----------------------------------------------" << endl;
    cout << "End of printSquare function." << endl << endl << endl;
}
