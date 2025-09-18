#include "fullTimeProfessorType.h"
#include "professorType.h"

//Default Constructor
fullTimeProfessorType::fullTimeProfessorType()
:professorType()
{
	//call default constructor for professorType, which calls personType default constructor
	setSalary(0.00);
	setStipend(0.00);
}


//Take in first and last name
fullTimeProfessorType::fullTimeProfessorType(string first, string last)
:professorType(first, last)
{
	setSalary(0.00);
	setStipend(0.00);
}


//Uber Constructor, calls uber constructor of professorType
//first, last, address, height, dob, gender, id, dept, degree, salary, stipend
fullTimeProfessorType::fullTimeProfessorType(string f, string l, string a, double h, string dob, char gen, string id, string dep, string deg, double sal, double stipend)
:professorType(f, l, a, h, dob, gen, id, dep, deg)
{
	setSalary(sal);
	setStipend(stipend);
}


//Setters
void fullTimeProfessorType::setSalary(double sal)
{
	empSalary = sal;
}


void fullTimeProfessorType::setStipend(double bonus)
{
	empStipend = bonus;
}


//Getters
double fullTimeProfessorType::getSalary() const
{
	return empSalary;
}


double fullTimeProfessorType::getStipend() const
{
	return empStipend;
}


double fullTimeProfessorType::calculatePay() const
{
	return empSalary + empStipend;
}


//Print
void fullTimeProfessorType::print() const
{
	cout << "Full Time Professor Details: " << endl;
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