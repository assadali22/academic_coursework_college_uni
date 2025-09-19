#include "vehicleType.h"
#include "planeType.h"

planeType::planeType()
{
    vehicleID = "0";
    color = "White";
    manufacturer = "EMPTY";
    year = "0000";
    stopped = true;
    movingForward = true;
}


planeType::planeType(string newVin, string newColor, string m, string y)
{
    vehicleID = newVin;
    color = newColor;
    manufacturer = m;
    year = y;
    stopped = true;
    movingForward = true;
}


void planeType::start()
{
    stopped = false;
    cout << year << " " << color << " " << manufacturer << " plane has been started and ready to fly in the air." << endl;

}


void planeType::stop()
{
    stopped = true;
    cout << year << " " << color << " " << manufacturer << " plane has been stopped (landed or stopped while on the ground)." << endl;
}


void planeType::moveForward()
{
    if (!getStopped())
    {
        movingForward = true;
        cout << year << " " << color << " " << manufacturer << " plane is moving forward in the air." << endl;
    }
    else
    {
        cout << year << " " << color << " " << manufacturer << " plane can't move because it has not been started, please start the plane." << endl;
    }
}


void planeType::moveBackward() //this will do nothing
{
    return;
}
