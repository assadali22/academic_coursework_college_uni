#ifndef TRIANGLETYPE_H
#define TRIANGLETYPE_H

#include "shapeType.h"
#include <cmath>

class triangleType: public shapeType
{
public:
    triangleType();
    triangleType(double b, double h);

    void setBase(double newB);
    void setHeight(double newH);

    double getBase() const;
    double getHeight() const;

    void printTriangle() const;

private:
    double base;
    double height;
    double hypotenuse;
};


#endif // TRIANGLETYPE_H
