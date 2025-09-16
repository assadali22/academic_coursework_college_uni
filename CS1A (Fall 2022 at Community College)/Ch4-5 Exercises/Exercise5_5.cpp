/*
Ch.5 Programming Exercises Problem 5

Write a program that prompts the user to enter two integers. The program
outputs how many numbers are multiples of 3 and how many
numbers are multiples of 5 between the two integers (inclusive).
*/

#include <iostream>

using namespace std;

int main()
{
    int num1 = 0, num2 = 0;
    int start = 0;
    int multiplesOf3 = 0;
    int multiplesOf5 = 0;


    cout << "Enter two integers: ";
    cin >> num1 >> num2;


    for (start = num1; start <= num2; start++)
    {
        if (start % 3 == 0)
        {
            multiplesOf3++;
        }

        if (start % 5 == 0)
        {
            multiplesOf5++;
        }
    }

    cout << "There are " << multiplesOf3 << " numbers that are a multiple of 3." << endl;
    cout << "There are " << multiplesOf5 << " numbers that are a multiple of 5." << endl;
    return 0;
}


/*
Sample Run 1
Enter two integers: 3 20
There are 6 numbers that are a multiple of 3.
There are 4 numbers that are a multiple of 5.


Sample Run 2
Enter two integers: 12 50
There are 13 numbers that are a multiple of 3.
There are 8 numbers that are a multiple of 5.


Sample Run 3
Enter two integers: 54 100
There are 16 numbers that are a multiple of 3.
There are 10 numbers that are a multiple of 5.
*/
