#ifndef RECTANGLETYPE_H
#define RECTANGLETYPE_H

#include "shapeType.h"

class rectangleType: public shapeType
{
public:
    rectangleType();
    rectangleType(double l, double w);

    //update perimeter and area when width or length changes in the setter function
    void setWidth(double W);
    void setLength(double L);

    double getWidth() const;
    double getLength() const;

    void printRect() const;

private:
    double length;
    double width;
};

#endif // RECTANGLETYPE_H
