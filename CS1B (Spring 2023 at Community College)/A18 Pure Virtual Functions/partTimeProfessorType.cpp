#include "partTimeProfessorType.h"
#include "professorType.h"

//Default Constructor
partTimeProfessorType::partTimeProfessorType():professorType()
{
	//Set default to 10 hours and $10 per hour
	setHoursWorked(10.00);
	setPayRate(10.00);
}


//Take in first and last name
partTimeProfessorType::partTimeProfessorType(string first, string last)
:professorType(first, last)
{
	//Set default to 10 hours and $10 per hour
	setHoursWorked(10.00);
	setPayRate(10.00);
}



//Uber constructor
//first, last, address, height, dob, gender, id, dept, degree, hours, payRate
partTimeProfessorType::partTimeProfessorType(string f, string l, string a, double h, string dob, char gen, string id, string dep, string deg, double hrs, double rate)
:professorType(f, l, a, h, dob, gen, id, dep, deg)
{
	setHoursWorked(hrs);
	setPayRate(rate);
}


//Setters
void partTimeProfessorType::setHoursWorked(double hrs)
{
	hoursWorked = hrs;
}


void partTimeProfessorType::setPayRate(double rate)
{
	payRate = rate;
}
	
	
//Getters
double partTimeProfessorType::getHoursWorked() const
{
	return hoursWorked;
}


double partTimeProfessorType::getPayRate() const
{
	return payRate;
}


//Print
void partTimeProfessorType::print() const
{
	cout << "Part Time Professor Details: " << endl;
	personType::print();
	cout << "Professor ID, Dep, Degree: " << endl;
	cout << "Employee ID: " << getEmpID() << endl;
	cout << "Department: " << getDepartment() << endl;
	cout << "Degree: " << getDegree() << endl;
	cout << "Wages: $" << calculatePay() << endl;
	cout << "-------------------------------------" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl;
}


double partTimeProfessorType::calculatePay() const
{
	return (payRate * hoursWorked);
}