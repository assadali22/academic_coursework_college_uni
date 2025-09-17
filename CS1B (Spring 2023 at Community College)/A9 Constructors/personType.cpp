#include "personType.h"

//Default constructor, call all setters in main
personType::personType()
{
	cout << "Default constructor called." << endl; //default constructor, no parameters
	setFirstName("EMPTY");
	setLastName("EMPTY");
	setAddress("EMPTY");
	setHeight(10);
	setDOB("MM/DD/YYYY");
	setGender('?');
}


//Call other setters except last and first name in main
personType::personType(string first, string last)
{
	cout << "First and last name constructor called." << endl;
	setFirstName(first);
	setLastName(last);
	setAddress("EMPTY");
	setHeight(10);
	setDOB("MM/DD/YYYY");
	setGender('?');

}


//Take in all variables with this constructor, no need to call setters in main if this is used.
personType::personType(string first, string last, string address, float height, string birthdate, char gender)
{
	cout << "Constructor to pass in all variables has been called." << endl;
	setFirstName(first);
	setLastName(last);
	setAddress(address);
	setHeight(height);
	setDOB(birthdate);
	setGender(gender);
}

/*
//Create default destructor but don't call it within main
//Destructor prevents memory leaks
//default destructor
personType::~personType()
{
	cout << "Default destructor called for " << getFirstName() << endl;

}
*/

//Setter Functions
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


//If height is less than 12, default is 12 inches
void personType::setHeight(float newHeight)
{
	if (newHeight <= 12)
	{
		height = 12;
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

float personType::getHeight() const //prevent changes to the data value
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
	cout << "First Name: " << getFirstName() << endl;
	cout << "Last Name: " << getLastName() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "Height: " << getHeight() << endl;
	cout << "Date of Birth: " << getDOB() << endl;
	cout << "Gender: " << getGender() << endl;
}


bool personType::equals(const personType& other) const
{
	bool same = false;
	//if (person.firstName = other.firstName)
	//getFirstName.compare belongs to string class
	if (getFirstName().compare(other.getFirstName()) == 0)
		same = true;
	else
		return false;

	if (getLastName().compare(other.getLastName()) == 0)
		same = true;
	else
		return false;

	if (getAddress().compare(other.getAddress()) == 0)
		same = true;
	else
		return false;

	if (getHeight() == other.getHeight())
		same = true;
	else
		return false;

	if (getDOB().compare(other.getDOB()) == 0)
		same = true;
	else
		return false;

	if (getGender() == other.getGender())
		same = true;
	else
		return false;


	return same;
}
