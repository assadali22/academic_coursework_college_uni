#include "vehicleType.h"

//Constructors
vehicleType::vehicleType()
{
    vehicleID = "0";
    color = "White";
    manufacturer = "EMPTY";
    year = "0000";
    stopped = true; //car is inactive
    movingForward = true;

}

vehicleType::vehicleType(string newVin, string newColor, string m, string y)
{
    vehicleID = newVin;
    color = newColor;
    manufacturer = m;
    year = y;
    stopped = true;
    movingForward = true;
}



void vehicleType::setColor(string c)
{
    color = c;
}


string vehicleType::getVehicleID() const
{
    return vehicleID;
}


string vehicleType::getColor() const
{
    return color;
}


string vehicleType::getManufacturer() const
{
    return manufacturer;
}


string vehicleType::getYear() const
{
    return year;
}


bool vehicleType::getMovingForward() const
{
    return movingForward;
}


bool vehicleType::getStopped() const
{
    return stopped;
}


//Operator overloading
bool vehicleType::operator==(const vehicleType& other) const
{
    return ((vehicleID == other.getVehicleID()) && (color == other.getColor()) && (manufacturer == other.getManufacturer()) && (year == other.getYear()));
}


bool vehicleType::operator!=(const vehicleType& other) const
{
    return !(*this == other);
}


ostream& operator<<(ostream& out, const vehicleType& v)
{
    out << "----------------------------------------------" << endl;
    out << "Vehicle ID (VIN): " << v.getVehicleID() << endl;
    out << "Color: " << v.getColor() << endl;
    out << "Manufacturer: " << v.getManufacturer() << endl;
    out << "Year: " << v.getYear() << endl;
    if (v.getStopped())
    {
        cout << "The vehicle is stopped." << endl;
    }
    else
    {
        cout << "The vehicle is active." << endl;
    }

    if (v.getMovingForward() && !v.getStopped())
    {
        cout << "The vehicle is moving forward." << endl;
    }
    else if (!v.getMovingForward() && !v.getStopped())
    {
        cout << "The vehicle is moving backward." << endl;
    }
    out << "----------------------------------------------" << endl;
    out << endl << endl;

    return out;
}
