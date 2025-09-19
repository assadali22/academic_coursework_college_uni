#include "shapeType.h"
#include "rectangleType.h"

rectangleType::rectangleType()
{
    shapeType();
    length = 0.00;
    width = 0.00;
    setShape("Rectangle");
}

//If length and width are passed in when object is declared, find its area and perimeter
rectangleType::rectangleType(double l, double w)
{
    shapeType();
    length = l;
    width = w;
    setArea(length * width);
    setPerimeter(length + length + width + width);
    setShape("Rectangle");
}


void rectangleType::setWidth(double W)
{
    //update area and perimeter of rectangle
    width = W;
    setArea(length * width);
    setPerimeter(length + length + width + width);
}


void rectangleType::setLength(double L)
{
    //update area and perimeter of rectangle
    length = L;
    setArea(length * width);
    setPerimeter(length + length + width + width);
}


double rectangleType::getWidth() const
{
    return width;
}


double rectangleType::getLength() const
{
    return length;
}



void rectangleType::printRect() const
{
    cout << "----------------------------------------------" << endl;
    cout << "Printing rectangle:" << endl;
    cout << "Rectangle length: " << length << endl;
    cout << "Rectangle width: " << width << endl;
    cout << "Rectangle area: " << getArea() << endl;
    cout << "Rectangle perimeter: " << getPerimeter() << endl;
    cout << "Rectangle color: " << getColor() << endl;
    cout << "----------------------------------------------" << endl;
    cout << "End of printRect function." << endl << endl << endl;
}
