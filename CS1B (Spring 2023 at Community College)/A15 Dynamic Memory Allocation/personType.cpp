#include "personType.h"

//Default constructor, call all setters in main
personType::personType()
{
	//default constructor, no parameters
	setFirstName("EMPTY");
	setLastName("EMPTY");
	setAddress("EMPTY");
	setHeight(24);
	setDOB("MM/DD/YYYY");
	setGender('?');
}


//Call other setters except last and first name in main
personType::personType(string first, string last)
{
	setFirstName(first);
	setLastName(last);
	setAddress("EMPTY");
	setHeight(24);
	setDOB("MM/DD/YYYY");
	setGender('?');

}


//Take in all variables with this constructor, no need to call setters in main if this is used.
personType::personType(string first, string last, string address, float height, string birthdate, char gender)
{
	setFirstName(first);
	setLastName(last);
	setAddress(address);
	setHeight(height);
	setDOB(birthdate);
	setGender(gender);
}

personType::~personType()
{
	cout << "Default destructor called for " << getFirstName() << endl;

}

void personType::setFirstName(string newName)
{
	firstName = newName;
}


void personType::setLastName(string newLastName)
{
	lastName = newLastName;
}

void personType::setAddress(string newAddress)
{
	address = newAddress;
}


//If height is less than 24, default is 24 inches
void personType::setHeight(float newHeight)
{
	if (newHeight <= 24)
	{
		height = 24;
	}
	else
	{
		height = newHeight;
	}
}


void personType::setDOB(string newDOB)
{
	dob = newDOB;
}


void personType::setGender(char newGender)
{
	gender = newGender;
}


//Getter Functions
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
