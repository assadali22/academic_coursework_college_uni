/*
Chapter 8 Programming Exercises Problem 1

Write a C++ program that declares an array alpha of 50 components
of type double. Initialize the array so that the first 25 components
are equal to the square of the index variable, and the last 25
components are equal to three times the index variable.
Output the array so that 10 elements per line are printed.

*/

#include <iostream>
using namespace std;

int main()
{
    double alpha[50];
    int i = 0;

    for (i = 0; i < 25; i++)
    {
        alpha[i] = i * i;
    }

    for (i = 25; i < 50; i++)
    {
        alpha[i] = 3 * i;
    }

    cout << "Array with index squared for first 25 elements and index * 3 for last 25 elements: " << endl;

    for (i = 0; i < 50; i++)
    {
        cout << alpha[i] << " ";
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }

    return 0;
}

/*
Sample Run 1
Array with index squared for first 25 elements and index * 3 for last 25 elements:
0 1 4 9 16 25 36 49 64 81
100 121 144 169 196 225 256 289 324 361
400 441 484 529 576 75 78 81 84 87
90 93 96 99 102 105 108 111 114 117
120 123 126 129 132 135 138 141 144 147
*/
