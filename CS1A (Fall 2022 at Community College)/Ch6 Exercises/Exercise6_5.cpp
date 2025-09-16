/*
Chapter 6 Programming Exercises Problem 5

Write a program to test chapter exercises 11 and 14.
*/

#include <iostream>
#include <cmath>
#include <ctype.h>
using namespace std;

bool isBlank(char& s);
bool findFloorProduct(double a, double b, double c);

int main()
{
    bool blankSpace;
    char ch;
    double num1 = 0;
    double num2 = 0;
    double num3 = 0;
    bool floorProduct;


    cout << "Enter character: ";
    cin.get(ch);

    blankSpace = isBlank(ch);

    if (blankSpace)
    {
        cout << "Blank space was entered." << endl;
    }
    else
    {
        cout << "Blank space was not entered." << endl;
    }

    cout << "Enter three doubles: ";
    cin >> num1 >> num2 >> num3;


    floorProduct = findFloorProduct(num1, num2, num3);

    if (floorProduct)
    {
        cout << "The floor of the product of the first two numbers is equal to the floor of the 3rd number." << endl;
    }
    else
    {
        cout << "The floor of the product of the first two numbers is NOT equal to the floor of the 3rd number." << endl;
    }
    return 0;
}



bool isBlank(char& s)
{
    if (isspace(s))
    {
        return true;
    }

    return false;

}

bool findFloorProduct(double a, double b, double c)
{
    if (floor(a * b) == floor(c))
    {
        return true;
    }
    return false;
}

/*
Sample Run 1
Enter character: u
Blank space was not entered.
Enter three doubles: 85.4 24.5 340.7
The floor of the product of the first two numbers is NOT equal to the floor of the 3rd number.


Sample Run 2
Enter character:
Blank space was entered.
Enter three doubles: 2.5 3.5 8.00
The floor of the product of the first two numbers is equal to the floor of the 3rd number.


Sample Run 3
Enter character:
Blank space was entered.
Enter three doubles: 2.5 7 17
The floor of the product of the first two numbers is equal to the floor of the 3rd number.

*/
