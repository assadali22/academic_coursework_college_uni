#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicleType.h"

class motorcycleType: public vehicleType
{
public:
    motorcycleType();
    motorcycleType(string newVin, string newColor, string m, string y);

    void start();
    void stop();
    void moveForward();
    void moveBackward();
};

#endif // MOTORCYCLE_H
