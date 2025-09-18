//-----------------------------------------------------------------------
//Purpose: This program uses operator overloading to compare the height -
//of two different people of personType. Operator overloading is also   -
//used to get the data and print the data.                              -
//-----------------------------------------------------------------------
//Algorithm:                                                            -
//Step 1: Create a double pointer array pointing to pointers to         -
//people of personType.                                                 -
//Step 2: Use a for loop to dynamically create each person through      -
//user input while overloading the input operator.                      -
//Step 3: Use a for loop to compare each person's height with ==, !=,   -
//>, and < with operator overloading, with each comparison displaying   -
//true or false.                                                        -
//Step 4: Quit                                                          -
//-----------------------------------------------------------------------

#include "personType.h"

int main()
{
	//overload operators to compare height of people
	cout << "Comparing people by height using operator overloading." << endl;
	personType **arr; //double pointer array
	arr = new personType*[PEOPLE];
	int i = 0;
	int j = 0;
	bool result = false;


	//when overloading >>, say cin >> arr[i]
	//Use for loop and get data from user
	for (i = 0; i < PEOPLE; i++)
	{
		arr[i] = new personType; //Create new pointer
		cout << "Person #" << i + 1 << endl;
		cin >> *arr[i]; //overloaded operator
		cout << "-------------------------------------" << endl;
	}
	cout << endl;

	cout << boolalpha;
	for (i = 0; i < PEOPLE - 1; i++)
	{
		cout << "-------------------------------------" << endl;
		cout << "Testing: " << *arr[i] << endl;
		for (j = 1; j < PEOPLE; j++)
		{
			cout << "Comparing: " << *arr[j] << endl;
			//Check for equal height
			cout << "arr[" << i << "] == arr[" << j << "]? ";
			result = (*arr[i] == *arr[j]); //dereference for the operator overloading to work so the function gets called
			cout << result << endl;

			//Check if height isn't equal
			cout << "arr[" << i << "] != arr[" << j << "]? ";
			result = (*arr[i] != *arr[j]);
			cout << result << endl;

			//Check if height of arr[i] is greater than arr[j]
			cout << "arr[" << i << "] > arr[" << j << "]? ";
			result = (*arr[i] > *arr[j]);
			cout << result << endl;

			//Check if height of arr[i] is less than arr[j]
			cout << "arr[" << i << "] < arr[" << j << "]? ";
			result = (*arr[i] < *arr[j]);
			cout << result << endl << endl;
		}
		cout << "-------------------------------------" << endl;
	}


	return 0;
}
