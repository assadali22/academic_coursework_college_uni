#ifndef VEHICLETYPE_H
#define VEHICLETYPE_H

#include <iostream>
#include <string>
using namespace std;

class vehicleType
{
public:

    vehicleType();
    vehicleType(string newVin, string newColor, string m, string y);

    //Pure virtual functions for polymorphism
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;

    //Setters and Getters
    void setColor(string c);

    string getVehicleID() const;
    string getColor() const;
    string getManufacturer() const;
    string getYear() const;

    bool getStopped() const; //returns true if car is stopped
    bool getMovingForward() const; //return true if car is moving in the forward direction


    //Operator Overloading
    bool operator==(const vehicleType& other) const;
    bool operator!=(const vehicleType& other) const;
    friend ostream& operator<<(ostream& out, const vehicleType& v);

protected:
    string vehicleID;
    string color;
    string manufacturer;
    string year;
    bool movingForward;
    bool stopped;


};


#endif // VEHICLETYPE_H
