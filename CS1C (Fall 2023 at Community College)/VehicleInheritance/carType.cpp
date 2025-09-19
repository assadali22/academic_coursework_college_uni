#include "vehicleType.h"
#include "carType.h"

//Constructors
carType::carType()
{
    vehicleID = "0";
    color = "White";
    manufacturer = "EMPTY";
    year = "0000";
    stopped = true; //car is inactive
    movingForward = true; //car moves forward. If false, it moves backward
}


carType::carType(string newVin, string newColor, string m, string y)
{
    vehicleID = newVin;
    color = newColor;
    manufacturer = m;
    year = y;
    stopped = true;
    movingForward = true;
}


void carType::start()
{
    stopped = false;
    cout << year << " " << color << " " << manufacturer << " has been started and ready to drive." << endl;
}


void carType::stop()
{
    stopped = true;
    cout << year << " " << color << " " << manufacturer << " has been stopped." << endl;
}


void carType::moveForward()
{
    if (!getStopped())
    {
        movingForward = true;
        cout << year << " " << color << " " << manufacturer << " is moving forward now." << endl;
    }
    else
    {
        cout << year << " " << color << " " << manufacturer << " can't move because it has not been started, please start the car." << endl;
    }
}


void carType::moveBackward()
{
    if (!getStopped())
    {
        movingForward = false;
        cout << year << " " << color << " " << manufacturer << " is now moving backward in reverse." << endl;
    }
    else
    {
        cout << year << " " << color << " " << manufacturer << " can't move because it has not been started, please start the car." << endl;
    }
}

