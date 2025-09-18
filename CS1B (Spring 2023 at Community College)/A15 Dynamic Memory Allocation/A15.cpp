//-----------------------------------------------------------------------
//Purpose: This program uses an array of pointers to point to objects   -
//that are of personType.                                               -
//-----------------------------------------------------------------------
//Algorithm:                                                            -
//Step 1: Create an array that holds 5 pointers to people.			        -
//Step 2: Loop through the array and use the uber constructor to		    -
//pass in all the data members.											                    -
//Step 3: Loop through the pointer array and print each person by row.  -
//Step 4: Finally, loop through the array to deallocate the memory of	  -
//each person, setting the pointers to null.                            -
//Step 5: Quit															                            -
//-----------------------------------------------------------------------


#include "personType.h"
#include "studentType.h"
#include "professorType.h"

int main()
{
	string address;
	float height;
	string birth;
	char gender;
	//personType *personPtr[PEOPLE]; static array

	//Dyanmic Array, it will be one single array
	//Array of pointers
	personType **personPtr = NULL; //initialize double pointer
	personPtr = new personType*[PEOPLE];
	int i = 0;


	for (i = 0; i < PEOPLE; i++)
	{
		personPtr[i] = nullptr; //initalize to null
	}



	//create each person individually with uber constructor
	//Dynamically create a person
	personPtr[0] = new personType("Alex", "Thorne", "267 Rose Ave", 62.5, "07/18/1998", 'M');
	personPtr[1] = new personType("Thomas", "Rodriguez", "945 Washington Street", 64.0, "08/12/2001", 'M');
	personPtr[2] = new personType("Leslie", "Stewart", "99 Star Street", 64.0, "04/12/2001", 'F');
	personPtr[3] = new personType("Luna", "Winters", "24 Sunflower Road", 67.0, "03/21/1999", 'F');
	personPtr[4] = new personType("Steve", "Jones"); //User inputs rest of the data for Steve

	cout << "Enter address for " << personPtr[4]->getFirstName() << ": ";
	getline(cin, address);
	personPtr[4]->setAddress(address);

	cout << "Enter height for " << personPtr[4]->getFirstName() << ": ";
	cin >> height;
	personPtr[4]->setHeight(height);

	cin.ignore(100, '\n');
	cout << "Enter date of birth for " << personPtr[4]->getFirstName() << ": ";
	getline(cin, birth);
	personPtr[4]->setDOB(birth);

	cout << "Enter gender for for " << personPtr[4]->getFirstName() << ": ";
	cin >> gender;
	personPtr[4]->setGender(gender);


	for (i = 0; i < PEOPLE; i++)
	{
		personPtr[i]->print();
		//(*personPtr[i]).print();
	}


	for (i = 0; i < PEOPLE; i++)
	{
		personPtr[i] = NULL;
	}


	cout << "Freeing object memory.." << endl;
	for (i = 0; i < PEOPLE; i++)
	{
		delete personPtr[i];
	}


	cout << "Deleting dynamic array... " << endl;
	delete [] personPtr;

	return 0;
}

/*
Steve's Data
12 Walker Drive
65.5
08/03/1997
M
*/
