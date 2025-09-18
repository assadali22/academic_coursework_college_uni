#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>
using namespace std;
const int PEOPLE = 4;

class personType
{
public:

	personType(); //default constructor
	personType(string, string); //constructor takes first and last name
	personType(string, string, string, float, string, char); //constructor to take all variables
	~personType();
	personType(const personType &other); //copy constructor

	//Setters
	void setFirstName(string newName);
	void setLastName(string newLastName);
	void setAddress(string newAddress);
	void setHeight(float newHeight);
	void setDOB(string newDOB);
	void setGender(char newGender);
	void setMother(personType*);
	void setFather(personType*);
	
	//Getters
	string getFirstName() const;
    string getLastName() const;
    string getAddress() const;
    float getHeight() const;
    string getDOB() const;
    char getGender() const;
	personType* getMother() const; //add const to fix issue with "passing const personType as 'this' argument discards qualifiers
	personType* getFather() const; //add const to fix issue with "passing const personType as 'this' argument discards qualifiers
	
	virtual void print() const;
    bool equals(const personType&) const;

private:
    string firstName;
    string lastName;
    string address;
    double height;
    string dob;
    char gender;
	personType *mother;
	personType *father;
};


#endif