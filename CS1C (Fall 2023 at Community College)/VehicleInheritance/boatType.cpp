#include "vehicleType.h"
#include "boatType.h"

boatType::boatType()
{
    vehicleID = "0";
    color = "White";
    manufacturer = "EMPTY";
    year = "0000";
    stopped = true;
    movingForward = true;
}


boatType::boatType(string newVin, string newColor, string m, string y)
{
    vehicleID = newVin;
    color = newColor;
    manufacturer = m;
    year = y;
    stopped = true;
    movingForward = true;
}


void boatType::start()
{
    stopped = false;
    cout << year << " " << color << " " << manufacturer << " boat has been started and ready for the water." << endl;
}


void boatType::stop()
{
    stopped = true;
    cout << year << " " << color << " " << manufacturer << " boat has been stopped and idle on water." << endl;
}


void boatType::moveForward()
{
    if (!getStopped())
    {
        movingForward = true;
        cout << year << " " << color << " " << manufacturer << " boat is moving forward on the water." << endl;
    }
    else
    {
        cout << year << " " << color << " " << manufacturer << " boat can't move because it has not been started, please start the boat." << endl;
    }
}

void boatType::moveBackward()
{
    return;
}
