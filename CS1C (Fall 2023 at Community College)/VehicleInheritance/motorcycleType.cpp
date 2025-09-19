#include "vehicleType.h"
#include "motorcycleType.h"

motorcycleType::motorcycleType()
{
    vehicleID = "0";
    color = "White";
    manufacturer = "EMPTY";
    year = "0000";
    stopped = true;
    movingForward = true;
}


motorcycleType::motorcycleType(string newVin, string newColor, string m, string y)
{
    vehicleID = newVin;
    color = newColor;
    manufacturer = m;
    year = y;
    stopped = true;
    movingForward = true;
}


void motorcycleType::start()
{
    stopped = false;
    cout << year << " " << color << " " << manufacturer << " motorcycle has been started and ready for the road." << endl;
}


void motorcycleType::stop()
{
    stopped = true;
    cout << year << " " << color << " " << manufacturer << " motorcycle has been stopped." << endl;
}


void motorcycleType::moveForward()
{
    if (!getStopped())
    {
        movingForward = true;
        cout << year << " " << color << " " << manufacturer << " motorcycle is moving forward on the road." << endl;
    }
    else
    {
        cout << year << " " << color << " " << manufacturer << " motorcycle can't move because it has not been started, please start the motorcycle." << endl;
    }
}


void motorcycleType::moveBackward()
{
    if (!getStopped())
    {
        movingForward = false;
        cout << year << " " << color << " " << manufacturer << " motorcycle is now moving backward in reverse." << endl;
    }
    else
    {
        cout << year << " " << color << " " << manufacturer << " motorcycle can't move because it has not been started, please start the motorcycle." << endl;
    }
}
