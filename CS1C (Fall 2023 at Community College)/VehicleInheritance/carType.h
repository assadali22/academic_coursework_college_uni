#ifndef CARTYPE_H
#define CARTYPE_H

#include "vehicleType.h"

class carType: public vehicleType
{
public:

    carType();
    carType(string newVin, string newColor, string m, string y);

    void start();
    void stop();
    void moveForward();
    void moveBackward(); //a car can go backward


};

#endif // CARTYPE_H
