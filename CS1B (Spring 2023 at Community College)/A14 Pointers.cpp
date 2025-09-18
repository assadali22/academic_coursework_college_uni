//-----------------------------------------------------------------------
//Purpose: This program uses pointers to change the values of 5			    -
//different variables and then uses pointers to print the contents		  -
//of each variable.														                          -
//-----------------------------------------------------------------------
//Algorithm:                                                            -
//Step 1: Declare 3 int variables, one char variable, and a double      -
//variable with the specified values given in the HW assignment.	      -
//Step 2: Declare 5 pointers, one for each variable.					          -
//Step 3: Print the original values using their variable names.			    -
//Step 4: Use pointers to change the contents of each variable and		  -
//to print the contents of each variable.							             	    -
//Step 5: Quit                                                          -
//-----------------------------------------------------------------------


#include <iostream>
using namespace std;

int main()
{
	//Declare variables
	int x = 5;
	int y = 10;
	int z = 1;
	char c = 'A';
	double price = 5.2;

	//Declare the pointers to point to the address of each variable
	int *xptr = &x;
	int *yptr = &y;
	int *zptr = &z;
	char *cptr = &c;
	double *pricePtr = &price;

	//Print Original Data
	cout << "Before pointer change: " << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;
	cout << "c = " << c << endl;
	cout << "price = " << price << endl;

	//Change data values with pointers
	*xptr = 25;
	*yptr = 15;
	*zptr = -1;
	*cptr = 'z';
	*pricePtr = 19.99;

	//Print data with pointers
	cout << "After using pointers to change data values: " << endl;
	cout << "x = " << *xptr << endl;
	cout << "y = " << *yptr << endl;
	cout << "z = " << *zptr << endl;
	cout << "c = " << *cptr << endl;
	cout << "price = " << *pricePtr << endl;

	return 0;
}
