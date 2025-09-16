/*
Chapter 6 Programming Exercises Problem 9

Write a function, reverseDigit, that takes an integer as a parameter
and returns the number with its digits reversed. For example, the value
of reverseDigit(12345) is 54321; the value of reverseDigit(5600) is 65;
the value of reverseDigit(7008) is 8007; the value of reverseDigit(-532)
is 235.

*/

#include <iostream>
using namespace std;
int reverseDigit(int n);

int main()
{
    int userNum = 0;
    int digitReverse = 0;

    cout << "Enter an integer: ";
    cin >> userNum;

    digitReverse = reverseDigit(userNum);

    cout << "The integer with its numbers reversed is: " << digitReverse << endl;
    return 0;
}


int reverseDigit(int n)
{
    int remainder = 0;
    int reverse = 0;

    while (n != 0)
    {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n = n / 10;
    }

    return reverse;
}

/*
Sample Run 1
Enter an integer: 7008
The integer with its numbers reversed is: 8007


Sample Run 2
Enter an integer: -6485465
The integer with its numbers reversed is: -5645846

Sample Run 3
Enter an integer: 947
The integer with its numbers reversed is: 749
*/
