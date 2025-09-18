#include "personType.h"
#include "studentType.h"


//Default Constructor
studentType::studentType()
{
    setGPA(0.00);
    setID("EMPTY");
    setClassification("EMPTY");
}

//Constructor that takes in first and last name
studentType::studentType(string fName, string lName)
{
    personType::setFirstName(fName);
    personType::setLastName(lName);
    setGPA(0.00);
    setID("EMPTY");
    setClassification("EMPTY");
}

//Constructor that takes in first name, last name, GPA, classification, and ID
studentType::studentType(string fName, string lName, double studGPA, string newClass, string studID)
{
    personType::setFirstName(fName); //setFirstName(fName) also works on its own without scope resolution operator
    personType::setLastName(lName);
    setGPA(studGPA);
    setID(studID);
    setClassification(newClass);

}

//Uber Constructor, define a person and a student, take in all data.
studentType::studentType(string fName, string lName, string address, double height, string dob, char gender, double studGPA, string newClass, string studID)
{
	personType::setFirstName(fName);
    personType::setLastName(lName);
    personType::setAddress(address);
    personType::setHeight(height);
    personType::setDOB(dob);
    personType::setGender(gender);

	setGPA(studGPA);
    setID(studID);
    setClassification(newClass);
}


//Setters
void studentType::setGPA(double newGPA)
{
    gpa = newGPA;
}


void studentType::setID(string newID)
{
    id = newID;
}


void studentType::setClassification(string newClass)
{
    classification = newClass;
}


//Getters
double studentType::getGPA() const
{
    return gpa;
}


string studentType::getID() const
{
    return id;
}


string studentType::getClassification() const
{
    return classification;
}

//Print Data
void studentType::print() const
{
	personType::print(); //this should print data members from personType
    cout << "Student Information for " << personType::getFirstName() << ": " << endl;
    cout << "GPA: " << getGPA() << endl;
    cout << "ID Number: " << getID() << endl;
    cout << "Classification: " << getClassification() << endl;
    cout << "-------------------------------------" << endl;
    cout << endl;
}

//Equals method, compare data members from personType in addition
//to comparing ID, classification, and GPA
bool studentType::equals(const studentType& other) const
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

    //Compare Student Information
    //Compare GPA
    if (getGPA() == other.getGPA())
    {
        same = true;
    }
    else
    {
        return false;
    }

    //Compare ID
    if (getID().compare(other.getID()) == 0)
    {
        same = true;
    }
    else
    {
        return false;
    }

    //Compare Classification
    if (getClassification().compare(other.getClassification()) == 0)
    {
        same = true;
    }
    else
    {
        return false;
    }

    return same;
}
