#ifndef BOATTYPE_H
#define BOATTYPE_H
#include "vehicleType.h"

class boatType: public vehicleType
{
public:
    boatType();
    boatType(string newVin, string newColor, string m, string y);

    void start();
    void stop();
    void moveForward();

    void moveBackward(); //this will do nothing
};


#endif // BOATTYPE_H

