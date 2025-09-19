#ifndef SQUARETYPE_H
#define SQUARETYPE_H

#include "shapeType.h"

class squareType: public shapeType
{
public:
    squareType();
    squareType(double s);

    void setSide(double newSide);
    double getSide() const;

    void printSquare() const;

private:
    double side;
};

#endif // SQUARETYPE_H
