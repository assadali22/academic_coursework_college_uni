//-----------------------------------------------------------------------
//Purpose: This program extends the professorType class by adding       -
//pure virtual functions, making the class abstract. Two new classes,   -
//fullTimeProfessorType and partTimeProfessorType, are derived from     -
//professorType. Full time professor has a fixed salary and stipend     -
//(bonus) while the part time professor has a wage equal to pay rate    -
//multiplied by number of hours worked per week.                        -
//-----------------------------------------------------------------------
//Algorithm:                                                            -
//Step 1: Create an object fullTimeProfessorType, using the uber        -
//constructor to take in all the data.                                  -
//Step 2: Create an object partTimeProfessorType, using the uber        -
//constructor to take in all the data.                                  -
//Step 3: Call the print methods of each professor to show their        -
//information, employee information, and pay.                           -
//Step 4: Quit                                                          -
//-----------------------------------------------------------------------

#include "fullTimeProfessorType.h"
#include "partTimeProfessorType.h"

int main()
{
	//Uber constructors used
	//first, last, address, height, dob, gender, id, dept, degree, salary, stipend
	fullTimeProfessorType emp1("John", "Smith", "12 Bloom St", 67.5, "04/12/1992", 'M', "J-1245", "Computer Science", "M.S", 56000, 5700);
	partTimeProfessorType emp2("Chris", "Pratt", "64 Mushroom Way", 69.0, "08/17/1987", 'M', "M-1064", "Game Design", "B.S", 36.5, 43);
	
	//Print Data
	emp1.print();
	cout << endl;
	emp2.print();
	return 0;
}
