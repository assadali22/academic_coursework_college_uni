/*
Ch.5 Programming Exercises Problem 7
n = aK aK-1 aK-2 ... a1 a0
t = a0 - a1 + a2 - a3... + (-1)^k
It is known that n is divisible by 11 if and only if t is divisible
by 11. For example, suppose that n = 8784204.
Then t = 4 - 0 + 2 - 4 + 8 - 7 + 8 = 11.
Because 11 is divisible by 11, it follows that 8784204 is divisible by 11.

If n = 54063297, t = 7 - 9 + 2 - 3 + 6 - 0 + 4 - 5 = 2.
Because 2 is not divisible by 11, 54063297 is not divisible by 11.
Write a program that prompts the user to enter a positive integer
and then uses this criterion to determine whether the number is
divisible by 11.
*/


#include <iostream>

using namespace std;

int main()
{
    int userNum = 0;
    int n = 0;
    int t = 0;
    int remainder = 0;
    int remainder2 = 0;
    int temp = 0;

    cout << "Enter a positive integer: ";
    cin >> userNum;

    n = userNum;
    temp = n;

    while (n != 0)
    {
        remainder = n % 10;
        temp = n / 10;
        remainder2 = temp % 10;

        t = t + remainder - remainder2;

        n = n / 100;
    }

    if (t % 11 == 0)
    {
        cout << userNum << " is divisible by 11." << endl;
    }

    else
    {
        cout << userNum << " is NOT divisible by 11." << endl;
    }
    return 0;
}

/*
Sample Run 1
Enter a positive integer: 8784204
8784204 is divisible by 11.

Sample Run 2
Enter a positive integer: 54063297
54063297 is NOT divisible by 11.

Sample Run 3
Enter a positive integer: 62304
62304 is divisible by 11.

Sample Run 4
Enter a positive integer: 59469
59469 is NOT divisible by 11.

Sample Run 5
Enter a positive integer: 6540
6540 is NOT divisible by 11.
*/
