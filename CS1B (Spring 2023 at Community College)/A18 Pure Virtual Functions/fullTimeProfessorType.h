#ifndef FULLTIMEPROFESSORTYPE_H
#define FULLTIEMPROFESSORTYPE_H

#include "professorType.h"

class fullTimeProfessorType: public professorType
{
public:
	fullTimeProfessorType(); //call default constructor of professorType
	
	fullTimeProfessorType(string, string); //take in first and last name
	
	//Uber constructor
	//first, last, address, height, dob, gender, id, dept, degree, salary, stipend
	fullTimeProfessorType(string, string, string, double, string, char, string, string, string, double, double);
	
	//Setters
	void setSalary(double sal);
	void setStipend(double bonus);
	
	//Getters
	double getSalary() const;
	double getStipend() const;
	
	void print() const;
	double calculatePay() const;
	
private:
	double empSalary;
	double empStipend; //bonus
};

#endif