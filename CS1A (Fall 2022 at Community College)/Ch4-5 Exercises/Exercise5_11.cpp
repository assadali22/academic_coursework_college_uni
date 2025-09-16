/*
Ch.5 Programming Exercises Problem 11

The program in the Programming Example: Fibonacci Number does
not check whether the first number entered by the user is less than or
equal to the second number and whether both the numbers are nonnegative.
Also, the program does not check whether the user entered
a valid value for the position of the desired number in the Fibonacci
sequence. Rewrite that program so that it checks for these things.
*/

#include <iostream>
using namespace std;
int main()
{
    int previous1;
    int previous2;
    int current;
    int counter;
    int nthFibonacci;

    cout << "Enter the first two Fibonacci "
    << "numbers: ";
    cin >> previous1 >> previous2;
    cout << endl;

    while (previous1 < 0)
    {
        cout << "First number can't be negative. Re-enter first number: ";
        cin >> previous1;
    }

    while (previous2 < 0)
    {
        cout << "Second number can't be negative. Re-enter first number: ";
        cin >> previous2;
    }

    while (previous1 >= previous2)
    {
        cout << "First number can't be greater than or equal to the second. Re-enter first number: ";
        cin >> previous1;
    }

    cout << "The first two Fibonacci numbers are "
    << previous1 << " and " << previous2
    << endl;

    cout << "Enter the position of the desired "
    << "Fibonacci number: ";
    cin >> nthFibonacci;
    cout << endl;

    if (nthFibonacci == 1)
        current = previous1;
    else if (nthFibonacci == 2)
        current = previous2;
    else
    {
        counter = 3;

        while (counter <= nthFibonacci)
        {
            current = previous2 + previous1;
            previous1 = previous2;
            previous2 = current;
            counter++;
        }
    }

    cout << "The Fibonacci number at position "
    << nthFibonacci << " is " << current << endl;
    return 0;
}

/*
Sample Run 1
Enter the first two Fibonacci numbers: 14 5

First number can't be greater than or equal to the second. Re-enter first number: 3
The first two Fibonacci numbers are 3 and 5
Enter the position of the desired Fibonacci number: 6

The Fibonacci number at position 6 is 34


Sample Run 2
Enter the first two Fibonacci numbers: -5 5

First number can't be negative. Re-enter first number: 9
First number can't be greater than or equal to the second. Re-enter first number: 2
The first two Fibonacci numbers are 2 and 5
Enter the position of the desired Fibonacci number: 6

The Fibonacci number at position 6 is 31


Sample Run 3
Enter the first two Fibonacci numbers: -3 -1

First number can't be negative. Re-enter first number: 3
Second number can't be negative. Re-enter first number: 4
The first two Fibonacci numbers are 3 and 4
Enter the position of the desired Fibonacci number: 5

The Fibonacci number at position 5 is 18
*/
