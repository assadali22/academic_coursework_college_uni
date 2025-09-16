/*
Ch.5 Programming Exercises Problem 23

Write a complete program to test the code in Example 5-22.
*/



#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i, j;

    cout << "Multiplication table 10 across, 5 down" << endl;

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            cout << setw(3) << i * j;
        }

        cout << endl;
    }
    return 0;
}

/*
Sample Run 1
Multiplication table 10 across, 5 down
  1  2  3  4  5  6  7  8  9 10
  2  4  6  8 10 12 14 16 18 20
  3  6  9 12 15 18 21 24 27 30
  4  8 12 16 20 24 28 32 36 40
  5 10 15 20 25 30 35 40 45 50
