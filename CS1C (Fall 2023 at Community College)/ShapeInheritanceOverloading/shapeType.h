#ifndef SHAPETYPE_H
#define SHAPETYPE_H

#include <iostream>
#include <string>
using namespace std;

class shapeType
{
public:

    //Default constructor
    shapeType();

    //Getters
    double getPerimeter() const;
    double getArea() const;
    string getColor() const;
    string getShape() const;

    //Setters
    void setPerimeter(double p);
    void setArea(double a);
    void setColor(string c);
    void setShape(string s);


    //Operator overloading
    bool operator==(const shapeType& other) const; //using const at the end of the function so nothing changes in *this pointer, won't change the original object itself
    bool operator!=(const shapeType& other) const;
    friend ostream& operator<<(ostream&, const shapeType&); //return ostream& (ostream reference)


    void printShape() const;

private:
    double perimeter;
    double area;
    string color;
    string shape;
};



#endif // SHAPETYPE_H
