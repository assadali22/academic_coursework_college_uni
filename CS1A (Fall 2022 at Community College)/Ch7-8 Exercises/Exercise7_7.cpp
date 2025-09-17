/*
Chapter 7 Programming Exercises Problem 7


(Fraction calculator) Write a program that lets the user perform arithmetic
operations on fractions. Fractions are of the form a/b, in which a and
b are integers and b can't equal 0. Your program must be menu driven, allowing
the user to select the operation (+, -, *, or /) and input the numerator and
denominator of each fraction. Furthermore, your program must consist of
at least the following functions:

a. Function menu: This function informs the user about the program’s purpose,
explains how to enter data, and allows the user to select the operation.

b. Function addFractions: This function takes as input four integers representing
the numerators and denominators of two fractions, adds the
fractions, and returns the numerator and denominator of the result.
(Notice that this function has a total of six parameters.)

c. Function subtractFractions: This function takes as input four integers
representing the numerators and denominators of two fractions,
subtracts the fractions, and returns the numerator and denominator of
the result. (Notice that this function has a total of six parameters.)

d. Function multiplyFractions: This function takes as input four integers
representing the numerators and denominators of two fractions,
multiplies the fractions, and returns the numerators and denominators
of the result. (Notice that this function has a total of six parameters.)

e. Function divideFractions: This function takes as input four integers
representing the numerators and denominators of two fractions, divides
the fractions, and returns the numerator and denominator of the result.
(Notice that this function has a total of six parameters.)

Some sample outputs are:
3 / 4 + 2 / 5 = 23 / 20
2 / 3 * 3 / 5 = 6 / 15
Your answer need not be in the lowest terms.

*/

#include <iostream>
using namespace std;
char menu();
void addFractions(int n1, int d1, int n2, int d2, int& numResult, int& denomResult);
void subtractFractions(int n1, int d1, int n2, int d2, int& numResult, int& denomResult);
void multiplyFractions(int n1, int d1, int n2, int d2, int& numResult, int& denomResult);
void divideFractions(int n1, int d1, int n2, int d2, int& numResult, int& denomResult);

int main()
{
    char option;
    int num1 = 0;
    int num2 = 0;
    int denom1 = 0;
    int denom2 = 0;
    int numeratorResult = 0;
    int denominatorResult = 0;
    option = menu();

    cout << "Enter the first fraction: ";
    cin >> num1 >> denom1;

    cout << "Enter the second fraction: ";
    cin >> num2 >> denom2;


    if (option == '+')
    {
        addFractions(num1, denom1, num2, denom2, numeratorResult, denominatorResult);
    }
    else if (option == '-')
    {
        subtractFractions(num1, denom1, num2, denom2, numeratorResult, denominatorResult);
    }
    else if (option == '*')
    {
        multiplyFractions(num1, denom1, num2, denom2, numeratorResult, denominatorResult);
    }
    else if (option == '/')
    {
        divideFractions(num1, denom1, num2, denom2, numeratorResult, denominatorResult);
    }

    cout << num1 << " / " << denom1 << " " << option << " " << num2 << " / " << denom2 << " = " << numeratorResult << " / " << denominatorResult << endl;
    return 0;
}


char menu()
{
    char choice;
    cout << "This program does operations on fractions depending on the operator you choose." << endl;
    cout << "Enter two numbers a and b to represent the fraction a/b." << endl;
    cout << "Choose an operation (+, -, *, /): ";
    cin >> choice;

    return choice;
}


void addFractions(int n1, int d1, int n2, int d2, int& numResult, int& denomResult)
{
    if (d1 == d2)
    {
        numResult = n1 + n2;
        denomResult = d1;
    }
    else
    {
        numResult = (n1 * d2) + (n2 * d1);
        denomResult = d1 * d2;
    }
}


void subtractFractions(int n1, int d1, int n2, int d2, int& numResult, int& denomResult)
{
    if (d1 == d2)
    {
        numResult = n1 - n2;
        denomResult = d1;
    }
    else
    {
        numResult = (n1 * d2) - (n2 * d1);
        denomResult = d1 * d2;
    }
}


void multiplyFractions(int n1, int d1, int n2, int d2, int& numResult, int& denomResult)
{
    numResult = n1 * n2;
    denomResult = d1 * d2;
}


void divideFractions(int n1, int d1, int n2, int d2, int& numResult, int& denomResult)
{
    numResult = n1 * d2;
    denomResult = d1 * n2;
}


/*
Sample Run 1
This program does operations on fractions depending on the operator you choose.
Enter two numbers a and b to represent the fraction a/b.
Choose an operation (+, -, *, /): +
Enter the first fraction: 4 5
Enter the second fraction: 3 8
4 / 5 + 3 / 8 = 47 / 40

Sample Run 2
This program does operations on fractions depending on the operator you choose.
Enter two numbers a and b to represent the fraction a/b.
Choose an operation (+, -, *, /): -
Enter the first fraction: 2 9
Enter the second fraction: 1 5
2 / 9 - 1 / 5 = 1 / 45

Sample Run 3
This program does operations on fractions depending on the operator you choose.
Enter two numbers a and b to represent the fraction a/b.
Choose an operation (+, -, *, /): *
Enter the first fraction: 3 4
Enter the second fraction: 4 7
3 / 4 * 4 / 7 = 12 / 28

Sample Run 4
This program does operations on fractions depending on the operator you choose.
Enter two numbers a and b to represent the fraction a/b.
Choose an operation (+, -, *, /): /
Enter the first fraction: 6 10
Enter the second fraction: 2 7
6 / 10 / 2 / 7 = 42 / 20
*/
