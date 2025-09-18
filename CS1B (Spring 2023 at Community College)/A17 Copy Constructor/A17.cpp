//-----------------------------------------------------------------------
//Purpose: This program uses personType, studentType, and professorType -
//classes to demonstrate copy constructors and defines a pointer        -
//variable of personType to define a mother and father. The object of	  -
//personType will have their mother and father set by using the			    -
//setters for the mother and father. 3 people are dynamically created   -
//and one person will be created through a copy constructor.		     	  -
//-----------------------------------------------------------------------
//Algorithm:                                                            -
//Step 1: Create the pointer array that points to a personType   		    -
//object. The array will hold 4 pointers to people.						          -
//Step 2: Use a for loop to initialize each pointer in the array to		  -
//nullptr.																                              -
//Step 3: Dynamically create each person using the uber constructor.	  -
//Step 4: Use the copy constructor to create the 4th person, passing	  -
//in person[1] as the parameter.									                 	    -
//Step 5: Set the mother and father for the student (person[1]),		    -
//passing in the appropriate pointer and using the correct setter.		  -
//Step 6: Print the data using a for loop and polymorphism, using the	  -
//member access operator arrow to access the print member function		  -
//when working with pointers.										          	            -
//Step 7: Use a for loop to deallocate the memory of each person.		    -
//Step 8: Quit															                            -
//-----------------------------------------------------------------------

#include "personType.h"
#include "studentType.h"
#include "professorType.h"


int main()
{
	//Create the pointers
	personType **personPtr = nullptr; //initialize double pointer
	personPtr = new personType*[PEOPLE];
	int i = 0;
	
	
	for (i = 0; i < PEOPLE; i++)
	{
		personPtr[i] = nullptr; //initalize to null
	}
	
	//Dynamically create each person
	personPtr[0] = new personType("Amy", "Smith", "267 Rose Ave", 62.5, "07/18/1998", 'F');
	personPtr[1] = new studentType("Jesse", "Klein", "140 Blue Jay Road", 69.5, "04/17/1997", 'M', 3.75, "Senior", "J87525");
	personPtr[2] = new professorType("Jimmy", "Jones", "14 Dale Street", 68.5, "04/05/1987", 'M', "J-3791577", "Science", "M.S");
	
	//Use the copy constructor to create the 4th person
	personPtr[3] = new personType(*personPtr[1]);
	
	personPtr[1]->setMother(personPtr[0]); //set the mother for studentType object
	personPtr[1]->setFather(personPtr[2]); //set the father for studentType object
	
	
	//Print the data
	for (i = 0; i < PEOPLE; i++)
	{
		if (personPtr[i] != nullptr) //make sure the person exists
		{
			cout << "Person #" << i + 1 << ": " << endl;
			personPtr[i]->print(); //works correctly with polymorphism (virtual function)
		}
		
	}

	//Deallocate data
	for (i = 0; i < PEOPLE; i++)
	{
		delete personPtr[i];
	}
	
	
	return 0;
}
