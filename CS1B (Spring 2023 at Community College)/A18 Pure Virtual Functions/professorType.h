#ifndef PROFESSORTYPE_H
#define PROFESSORTYPE_H

#include "personType.h"

class professorType: public personType
{
public:
    //Constructors
    professorType(); //Default constructor
    professorType(string first, string last); //Constructor that takes in first and last name
	
	//Uber constructor
    professorType(string first, string last, string address, double height, string dob, char gender, string empID, string dep, string deg);

    //Setters
    void setEmpID(string newEmpID);
    void setDepartment(string dep);
    void setDegree(string deg);

    //Getters
    string getEmpID() const;
    string getDepartment() const;
    string getDegree() const;
	bool equals(const professorType& other) const;
	
	//Pure Virtual Functions (incomplete class, professorType becomes abstract class)
    virtual void print() const = 0; //print method removed in .cpp
	virtual double calculatePay() const = 0;
    

private:
    string employeeID;
    string department;
    string degree;
};


#endif