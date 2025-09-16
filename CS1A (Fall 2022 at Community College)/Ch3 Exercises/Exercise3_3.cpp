/*
Ch.3 Programming Exercises Problem 3
Write a program that prompts the user to enter the weight of a person
in kilograms and outputs the equivalent weight in pounds. Output both
the weights rounded to two decimal places. (Note that 1 kilogram 5
2.2 pounds.) Format your output with two decimal places
*/


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double kilograms = 0;
    double pounds = 0;

    cout << "Enter weight in kilograms: ";
    cin >> kilograms;
    cout << endl;

    pounds = 2.2 * kilograms;

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "The weight converted to pounds is " << pounds << " pounds." << endl;
    return 0;


}

/*
Sample Run 1
Enter weight in kilograms: 19

The weight converted to pounds is 41.80 pounds.

Sample Run 2
Enter weight in kilograms: 85

The weight converted to pounds is 187.00 pounds.

Sample Run 3
Enter weight in kilograms: 65.7

The weight converted to pounds is 144.54 pounds.


*/
