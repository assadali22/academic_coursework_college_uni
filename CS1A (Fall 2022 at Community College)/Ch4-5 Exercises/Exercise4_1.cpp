/*
Ch.4 Programming Exercises Problem 1

Write a program that prompts the user to input a number. The program
should then output the number and a message saying whether
the number is positive, negative, or zero.
*/

#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    cout << "Enter a number: ";
    cin >> number;

    if (number > 0)
    {
        cout << "The number is positive." << endl;
    }
    else if (number < 0)
    {
        cout << "The number is negative." << endl;
    }
    else if (number == 0)
    {
        cout << "The number is equal to zero." << endl;
    }
    return 0;
}

/*
Sample Run 1
Enter a number: 0
The number is equal to zero.

Sample Run 2
Enter a number: 44
The number is positive.


Sample Run 3
Enter a number: -32
The number is negative.

*/
