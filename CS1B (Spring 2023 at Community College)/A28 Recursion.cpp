//---------------------------------------------------------------------------
//Purpose: This program uses a recursive function to print a pattern of     -
//stars, with each half being symmetrical. The user enters the number of    -
//lines in the pattern and uses the recursive function to generate the      -
//pattern.                                                                  -
//---------------------------------------------------------------------------
//Algorithm:                                                                -
//Step 1: Have the user input the number of lines for the pattern of stars. -
//Step 2: The number of lines is passed into the recursive function and     -
//uses for loops to print the star pattern until the base case is reached,  -
//printing the other half of the stars.                                     -
//Step 3: Quit                                                              -
//---------------------------------------------------------------------------

#include <iostream>
using namespace std;
void printStar(int n);

int main()
{
	int numLines;

	cout << "Enter the number of lines for star pattern: ";
	cin >> numLines;

	printStar(numLines);

	return 0;
}


void printStar(int n)
{
	int i;

	if (n == 0) //BASE CASE to start printing the other half
	{
		return;
	}
	else
	{
		//GENERAL CASE
		for (i = 0; i < n; i++)
		{
			cout << "*";
		}
		cout << endl;

		printStar(n - 1); //recursion in the middle

		//This will print the 2nd half
		for (i = 0; i < n; i++)
		{
			cout << "*";
		}
		cout << endl;
		//2 for loops with the recursion sandwiched in the middle
	}
}
