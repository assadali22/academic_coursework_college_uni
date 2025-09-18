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
	setMother(nullptr);
	setFather(nullptr);
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
	setMother(nullptr);
	setFather(nullptr);

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
	setMother(nullptr);
	setFather(nullptr);
}

//Destructor
personType::~personType()
{
	cout << "Default destructor called for " << getFirstName() << endl;

}

//Copy constructor
personType::personType(const personType &other)
{
	setFirstName(other.getFirstName());
	setLastName(other.getLastName());
	setAddress(other.getAddress());
	setHeight(other.getHeight());
	setDOB(other.getDOB());
	setGender(other.getGender());
	setMother(other.getMother()); //error here because getMother doesn't have const in function prototype, must have const.
	setFather(other.getFather()); //error here because getFather doesn't have const in function prototype, must have const.
}


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


void personType::setMother(personType* m)
{
	mother = m;
}


void personType::setFather(personType* f)
{
	father = f;
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

personType* personType::getMother() const
{
	return mother;
}

personType* personType::getFather() const
{
	return father;
}


//Print function
void personType::print() const
{
    cout << "-------------------------------------" << endl;
    cout << "First name: " << getFirstName() << endl;
    cout << "Last name: " << getLastName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Height: " << getHeight() << endl;
    cout << "Date of Birth: " << getDOB() << endl;
    cout << "Gender: " << getGender() << endl;
	if (mother != nullptr)
	{
		cout << "Mother = " << mother->getFirstName() << " " << mother->getLastName() << endl;
	}
	else
	{
		cout << "Mother = Unknown" << endl;
	}
	
	if (father != nullptr)
	{
		cout << "Father = " << father->getFirstName() << " " << father->getLastName() << endl;
	}
	else
	{
		cout << "Father = Unknown" << endl;
	}
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


/*
	if (mother != nullptr)
	{
		cout << "Mother = " << mother->getFirstName() << " " << mother->getLastName() << endl;
	}
	else
	{
		cout << "Mother = Unknown" << endl;
	}
	
	if (father != nullptr)
	{
		cout << "Father = " << father->getFirstName() << " " << father->getLastName() << endl;
	}
	else
	{
		cout << "Father = Unknown" << endl;
	}
	
	
*/