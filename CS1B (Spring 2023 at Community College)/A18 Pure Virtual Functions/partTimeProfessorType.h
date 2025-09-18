#ifndef PARTTIMEPROFESSORTYPE_H
#define PARTTIEMPROFESSORTYPE_H

#include "professorType.h"

class partTimeProfessorType: public professorType
{
public:
	partTimeProfessorType(); //call default constructor of professorType
	
	partTimeProfessorType(string, string); //take in first and last name
	
	//Uber constructor
	//first, last, address, height, dob, gender, id, dept, degree, hours, payRate
	partTimeProfessorType(string, string, string, double, string, char, string, string, string, double, double);
	
	//Setters
	void setHoursWorked(double hrs);
	void setPayRate(double rate);
	
	//Getters
	double getHoursWorked() const;
	double getPayRate() const;
	
	void print() const;
	double calculatePay() const;
	
	
private:
	double hoursWorked;
	double payRate; //money per hour
};


#endif