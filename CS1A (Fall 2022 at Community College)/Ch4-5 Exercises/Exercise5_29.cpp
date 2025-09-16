/*
Ch.5 Programming Exercises Problem 29
Let n be a nonnegative integer. The factorial of n, written n!, is defined
by 0! = 1, n! = 1 * 2 * 3 ... * n, n >= 1.
4! = 1 * 2 * 3 * 4;

Write a program that prompts the user to enter a nonnegative integer
and outputs the factorial of the number.
*/

#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int product = 1;
    int i = 0;

    cout << "Enter n: ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        product = product * i;
    }


    cout << "The factorial of " << n << " is " << n << "! = " << product << endl;
    return 0;
}

/*
Sample Run 1
Enter n: 4
The factorial of 4 is 4! = 24

Sample Run 2
Enter n: 6
The factorial of 6 is 6! = 720

Sample Run 3
Enter n: 10
The factorial of 10 is 10! = 3628800
*/
