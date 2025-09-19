#include "vehicleType.h"
#include "carType.h"
#include "boatType.h"
#include "planeType.h"
#include "motorcycleType.h"

using namespace std;

int main()
{
    //Create 2 cars
    cout << "Creating 2 cars." << endl;
    carType c1("23HMM31", "Red", "Honda", "2019");
    carType c2;

    c1.start();
    cout << "Car 1 data: " << endl;
    cout << c1 << endl;


    cout << "Execute c2 = c1 statement" << endl;
    c2 = c1;
    c2.start();
    c2.moveBackward();
    cout << "Car 2 data: " << endl;
    cout << c2;


    cout << "Compare car 1 and car 2 with overloaded == and !=" << endl;
    if (c1 == c2)
    {
        cout << "c1 == c2 is true" << endl;
    }
    else
    {
        cout << "c1 == c2 is false" << endl;
    }

    if (c1 != c2)
    {
        cout << "c1 != c2 is true" << endl;
    }
    else
    {
        cout << "c1 != c2 is false" << endl;
    }
    cout << endl << endl;


    //Create a 3rd car
    cout << "Creating car c3." << endl;
    carType c3("455TR21", "Black", "Ford", "2020");

    //Try to move forward or backward
    cout << "Test c3 to move forward or backward if it is not started." << endl;
    c3.moveForward();
    c3.moveBackward();

    cout << "Car 3 data: " << endl << endl;
    cout << c3 << endl;
    cout << "Compare car 1 and car 3 with overloaded != operator" << endl;
    if (c1 != c3)
    {
        cout << "c1 != c3 is true" << endl;
    }
    else
    {
        cout << "c1 != c3 is false" << endl;
    }
    cout << endl;

    cout << "************************************************************" << endl;

    //-------------------------------------------------------------------------
    //Create 2 boats
    cout << "Creating 2 boats." << endl;
    boatType boat1("B234NA5", "Blue", "Beneteau", "2016");
    boatType boat2("B538RF6", "Orange", "Pro-Line", "2018");
    boat1.moveForward();
    boat1.start();
    boat2.start();

    cout << "Boat 1 data: " << endl;
    cout << boat1 << endl;
    cout << "Boat 2 data: " << endl;
    cout << boat2 << endl;

    cout << "Change boat1 color to yellow" << endl;
    boat1.setColor("Yellow");

    cout << boat1 << endl;

    if (boat1 == boat2)
    {
        cout << "boat1 == boat2 is true" << endl;
    }
    else
    {
        cout << "boat1 == boat2 is false" << endl;
    }
    cout << endl;

    cout << "************************************************************" << endl;

    //-------------------------------------------------------------------------
    //Create 2 planes
    cout << "Creating 2 planes." << endl;
    planeType plane1("P4389B12", "Blue", "Airbus", "2022");
    planeType plane2("D3249C98", "White", "Boeing", "2023");
    planeType plane3;

    cout << "Execute plane3 = plane2" << endl;
    plane3 = plane2;
    plane1.moveForward();

    cout << "Start plane3" << endl;
    plane3.start();

    cout << "Plane 1 data: " << endl;
    cout << plane1 << endl;
    cout << "Plane 2 data: " << endl;
    cout << plane2 << endl;
    cout << "Plane 3 data: " << endl;
    cout << plane3 << endl;

    if (plane1 == plane2)
    {
        cout << "plane1 == plane2 is true" << endl;
    }
    else
    {
        cout << "plane1 == plane2 is false" << endl;
    }

    if (plane2 == plane3)
    {
        cout << "plane2 == plane3 is true" << endl;
    }
    else
    {
        cout << "plane2 == plane3 is false" << endl;
    }
    cout << endl;

    cout << "************************************************************" << endl;

    //-------------------------------------------------------------------------
    //Create 2 motorcycles
    cout << "Creating 2 motorcycles." << endl;
    motorcycleType motor1("843HT71", "Red", "Kawasaki", "2020");
    motorcycleType motor2("384JN55", "Green", "Harley-Davidson", "2021");

    motor1.moveForward();
    motor1.start();
    motor1.moveBackward();

    cout << "Data for motor1:" << endl;
    cout << motor1 << endl;
    cout << "Data for motor2:" << endl;
    cout << motor2 << endl;

    motor2.setColor("Purple");
    cout << "After changing motor2 color to purple, motor2 data is:" << endl;
    cout << motor2 << endl;

    if (motor1 != motor2)
    {
        cout << "motor1 != motor2 is true" << endl;
    }
    else
    {
        cout << "motor1 != motor2 is true" << endl;
    }

    return 0;
}
