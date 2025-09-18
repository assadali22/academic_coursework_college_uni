#include "personType.h"
#include "professorType.h"

//Default constructor
professorType::professorType()
{
    setEmpID("EMPTY");
    setDepartment("EMPTY");
    setDegree("EMPTY");
}

//Take in first and last name with this constructor
professorType::professorType(string first, string last)
{
    personType::setFirstName(first);
    personType::setLastName(last);
    setEmpID("EMPTY");
    setDepartment("EMPTY");
    setDegree("EMPTY");
}

//Take in all data members that define a person and a professor. (Uber constructor)
professorType::professorType(string first, string last, string address, double height, string dob, char gender, string empID, string dep, string deg)
{
    personType::setFirstName(first);
    personType::setLastName(last);
    personType::setAddress(address);
    personType::setHeight(height);
    personType::setDOB(dob);
    personType::setGender(gender);

    setEmpID(empID);
    setDepartment(dep);
    setDegree(deg);
}


//Setters
void professorType::setEmpID(string newEmpID)
{
    employeeID = newEmpID;
}


void professorType::setDepartment(string dep)
{
    department = dep;
}


void professorType::setDegree(string deg)
{
    degree = deg;
}


//Getters
string professorType::getEmpID() const
{
    return employeeID;
}


string professorType::getDepartment() const
{
    return department;
}


string professorType::getDegree() const
{
    return degree;
}

//Print method
void professorType::print() const
{
    personType::print();
    cout << "Professor Information for " << personType::getFirstName() << ": " << endl;
    cout << "Employee ID: " << getEmpID() << endl;
    cout << "Department: " << getDepartment() << endl;
    cout << "Degree: " << getDegree() << endl;
    cout << "-------------------------------------" << endl;
	cout << endl;
}

//Equals method, compare 2 objects and their
//data members that make up a person in addition to
//employee ID, department, and degree.
bool professorType::equals(const professorType& other) const
{
    bool same = false;

    //Compare First Name
    if (getFirstName().compare(other.getFirstName()) == 0)
    {
        same = true;
    }
    else
    {
        return false;
    }

    //Compare Last Name
    if (getLastName().compare(other.getLastName()) == 0)
    {
        same = true;
    }
    else
    {
        return false;
    }

    //Compare Address
    if (getAddress().compare(other.getAddress()) == 0)
    {
        same = true;
    }
    else
    {
        return false;
    }

    //Compare Height
    if (getHeight() == other.getHeight())
    {
        same = true;
    }
    else
    {
        return false;
    }

    //Compare Birthdate
    if (getDOB().compare(other.getDOB()) == 0)
    {
        same = true;
    }
    else
    {
        return false;
    }

    //Compare Gender
    if (getGender() == other.getGender())
    {
        same = true;
    }
    else
    {
        return false;
    }

    //Compare Professor Information
    //Compare Employee ID
    if (getEmpID().compare(other.getEmpID()) == 0)
    {
        same = true;
    }
    else
    {
        return false;
    }

    //Compare Department
    if (getDepartment().compare(other.getDepartment()) == 0)
    {
        same = true;
    }
    else
    {
        return false;
    }

    //Compare Degree
    if (getDegree().compare(other.getDepartment()) == 0)
    {
        same = true;
    }
    else
    {
        return false;
    }

    return same;
}
