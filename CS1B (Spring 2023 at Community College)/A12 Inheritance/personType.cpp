#include "personType.h"

//Default Constructor
personType::personType()
{
    setFirstName("EMPTY");
    setLastName("EMPTY");
    setAddress("EMPTY");
    setHeight(0.00);
    setDOB("EMPTY");
    setGender('?');
}


//Setters
void personType::setFirstName(string first)
{
    firstName = first;
}

void personType::setLastName(string last)
{
    lastName = last;
}


void personType::setAddress(string newAdd)
{
    address = newAdd;
}


void personType::setHeight(float h)
{
    height = h;
}


void personType::setDOB(string birth)
{
    dob = birth;
}

void personType::setGender(char gen)
{
    gender = toupper(gen);
}


//Getters
string personType::getFirstName() const
{
    return firstName;
}


string personType::getLastName() const
{
    return lastName;
}

string personType::getAddress() const
{
    return address;
}

float personType::getHeight() const
{
    return height;
}

string personType::getDOB() const
{
    return dob;
}

char personType::getGender() const
{
    return gender;
}


//Print Method
void personType::print() const
{
    cout << "-------------------------------------" << endl;
    cout << "First name: " << getFirstName() << endl;
    cout << "Last name: " << getLastName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Height: " << getHeight() << endl;
    cout << "Date of Birth: " << getDOB() << endl;
    cout << "Gender: " << getGender() << endl;
    cout << "-------------------------------------" << endl;
    cout << endl;
}

//Equals method
bool personType::equals(const personType& other) const
{
     //person1.equals(person2);
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

     return same;
}
