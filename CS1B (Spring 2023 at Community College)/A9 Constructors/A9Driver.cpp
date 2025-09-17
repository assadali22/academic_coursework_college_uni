//-----------------------------------------------------------------------
//Purpose: This program modifies assignment A8 on the personType class  -
//to include 3 constructors. 3 people are created instead of 5.         -
//There is a default constructor, a constructor to take in just the     -
//first and last name, and a constructor to take in all the			        -
//variables. After calling the constructors, the appropriate            -
//setters are called to fill in the other data members and finally      -
//print out the data of 3 people.                                       -
//-----------------------------------------------------------------------
//Algorithm:											                                      -
//Step 1: Create 3 objects to be a class personType. This identifies    -
//3 unique people.													                            -
//Step 2: Call the appropriate setters to fill the other data members.  -
//Step 3: Print out the data for each of the 3 different people.			  -
//Step 4: Quit															                            -
//-----------------------------------------------------------------------

#include "personType.h"


//DRIVER
int main()
{
	personType person1;
	personType person2("John", "Booth"); //calls appropriate prototype using the arguments
	personType person3("Sam", "Smith", "98 Orange Street", 70.00, "05/16/2001", 'M');
	string fname;
	string lname;
	string address;
	float height;
	string birthdate;
	char gen;
	
	//Call setters for person1
	cout << "Enter first name for person #1: ";
	cin >> fname;
	person1.setFirstName(fname); //person.personType::setFirstName(input)
	
	cout << "Enter last name for person #1: ";
	cin >> lname;
	person1.setLastName(lname);
	
	cin.ignore(100, '\n');
	cout << "Enter address for person #1: ";
	getline(cin, address);
	person1.setAddress(address);
	
	cout << "Enter height in inches for person #1: ";
	cin >> height;
	person1.setHeight(height);
	
	cout << "Enter date of birth (MM/DD/YYYY) for person #1: ";
	cin >> birthdate;
	person1.setDOB(birthdate);
	
	cout << "Enter gender (M for male, F for female) for person #1: ";
	cin >> gen;
	gen = toupper(gen);
	person1.setGender(gen);
	
	cout << endl;
	//Call setters for person2
	cin.ignore(100, '\n');
	cout << "Enter address for person #2: ";
	getline(cin, address);
	person2.setAddress(address);
	
	cout << "Enter height in inches for person #2: ";
	cin >> height;
	person2.setHeight(height);

	cout << "Enter date of birth (MM/DD/YYYY) for person #2: ";
	cin >> birthdate;
	person2.setDOB(birthdate);
	
	cout << "Enter gender (M for male, F for female) for person #2: ";
	cin >> gen;
	gen = toupper(gen);
	person2.setGender(gen);
	
	cout << fixed << showpoint << setprecision(2);
	//Print Data
	cout << endl << endl;
	cout << "Person #1: " << endl;
	cout << "--------------------------------------------------------------" << endl;
	person1.print();
	cout << "--------------------------------------------------------------" << endl << endl;
	
	cout << "Person #2: " << endl;
	cout << "--------------------------------------------------------------" << endl;
	person2.print();
	cout << "--------------------------------------------------------------" << endl << endl;
	
	cout << "Person #3: " << endl;
	cout << "--------------------------------------------------------------" << endl;
	person3.print();
	cout << "--------------------------------------------------------------" << endl << endl;
	
	return 0;
}
