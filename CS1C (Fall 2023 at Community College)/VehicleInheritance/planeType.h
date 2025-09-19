#ifndef PLANETYPE_H
#define PLANETYPE_H

#include "vehicleType.h"

class planeType: public vehicleType
{
public:
    planeType();
    planeType(string newVin, string newColor, string m, string y);

    void start();
    void stop();
    void moveForward();

    void moveBackward(); //this will do nothing
};

#endif // PLANETYPE_H
