/*
Ch.4 Programming Exercises Problem 9

Write a program that mimics a calculator. The program should take as
input floating point numbers and the operation to be performed.
It should then output the numbers, the operator, and the result.

*/

#include <iostream>
using namespace std;

int main()
{
    char operation;
    double num1 = 0;
    double num2 = 0;
    double result = 0;

    cout << "Enter two floating point numbers: ";
    cin >> num1 >> num2;

    cout << "Enter operation to be performed (+, -, *, /): ";
    cin >> operation;

    if (operation == '+')
    {
        result = num1 + num2;
        cout << num1 << " + " << num2 << " = " << result << endl;
    }
    else if (operation == '-')
    {
        result = num1 - num2;
        cout << num1 << " - " << num2 << " = " << result << endl;
    }
    else if (operation == '*')
    {
        result = num1 * num2;
        cout << num1 << " * " << num2 << " = " << result << endl;
    }
    else if (operation == '/')
    {
        if (num2 == 0)
        {
            cout << "Division by 0 error." << endl;
        }
        else
        {
            result = num1 / num2;
            cout << num1 << " / " << num2 << " = " << result << endl;
        }
    }
    return 0;

}

/*
Sample Run 1
Enter two floating point numbers: 7.5 8.3
Enter operation to be performed (+, -, *, /): +
7.5 + 8.3 = 15.8


Sample Run 2
Enter two floating point numbers: 2.8 4.4
Enter operation to be performed (+, -, *, /): -
2.8 - 4.4 = -1.6

Sample Run 3
Enter two floating point numbers: 4.7 0
Enter operation to be performed (+, -, *, /): /
Division by 0 error.
*/

