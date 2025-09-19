#ifndef CIRCLETYPE_H
#define CIRCLETYPE_H

#include "shapeType.h"

class circleType: public shapeType
{
public:
    circleType();
    circleType(double rad);

    double getRadius() const;
    void setRadius(double r); //area and perimeter is updated in here

    void printCircle() const;

private:
    double radius;
};

#endif // CIRCLETYPE_H
