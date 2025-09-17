#ifndef PERSONTYPE_H_
#define PERSONTYPE_H_

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;
//FUNCTION PROTOTYPES, code for changing values, etc is done in personType.cpp
class personType
{
public:

	personType(); //default constructor
	personType(string, string); //constructor takes first and last name
	personType(string, string, string, float, string, char); //constructor to take all variables
	//~personType(); Destructor prevents memory leaks


	//SETTERS
	void setFirstName(string newName);
	void setLastName(string newLastName);
	void setAddress(string newAddress);
	void setHeight(float newHeight);
	void setDOB(string newDOB);
	void setGender(char newGender);
	
	
	//GETTERS will have const after each function
	string getFirstName() const;
	string getLastName() const;
	string getAddress() const;
	float getHeight() const; //prevent changes to the data value
	string getDOB() const;
	char getGender() const;
	
	void print() const;
	bool equals(const personType&) const;
	
private:
	string firstName;
	string lastName;
	string address;
	float height;
	string dob;
	char gender;
};

#endif