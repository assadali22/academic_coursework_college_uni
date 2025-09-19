#include "shapeType.h"

//Default constructor
shapeType::shapeType()
{
    area = 0.00;
    perimeter = 0.00;
    color = "Clear";
    shape = "";
}

//Getters
double shapeType::getPerimeter() const
{
    return perimeter;
}

double shapeType::getArea() const
{
    return area;
}

string shapeType::getColor() const
{
    return color;
}

string shapeType::getShape() const
{
    return shape;
}

//Setters
void shapeType::setColor(string c)
{
    color = c;
}

void shapeType::setPerimeter(double p)
{
    perimeter = p;
}

void shapeType::setArea(double a)
{
    area = a;
}

void shapeType::setShape(string s)
{
    shape = s;
}


//Operator overloading
bool shapeType::operator==(const shapeType& other) const
{
    return ((area == other.getArea()) && (color.compare(other.getColor()) == 0));
    // i forgot to compare perimeter
}



bool shapeType::operator!=(const shapeType& other) const
{
    return ((area != other.getArea()) || (color.compare(other.getColor()) != 0));
}


ostream& operator<<(ostream& osObject, const shapeType& s)
{
    osObject << "Using overloaded cout: " << endl;
    cout << "----------------------------------------------" << endl;
    osObject << "Shape Type: " << s.getShape() << endl;
    osObject << "Area: " << s.getArea() << endl;
    osObject << "Perimeter: " << s.getPerimeter() << endl;
    osObject << "Color: " << s.getColor() << endl;
    cout << "----------------------------------------------" << endl << endl;

    return osObject;
}


void shapeType::printShape() const
{
    cout << "----------------------------------------------" << endl;
    cout << "Shape type: " << shape << endl;
    cout << "Shape area: " << area << endl;
    cout << "Shape perimeter: " << perimeter << endl;
    cout << "Shape color: " << color << endl;
    cout << "----------------------------------------------" << endl;
    cout << "End of printShape function." << endl << endl << endl;
}
