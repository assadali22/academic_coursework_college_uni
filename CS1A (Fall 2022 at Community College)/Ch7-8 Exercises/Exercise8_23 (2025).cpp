/*
Chapter 8 Programming Exercises Problem 23
Write a program that uses a 3x3 array and randomly place each
integer from 1 to 9 into the nine squares. The program calculates the
magic number by adding all the numbers in the array and then dividing
the sum by 3. The 3x3 array is a magic square if the sum of each
row, each column, and each diagonal is equal to the magic number.
Your program must contain at least the following functions: a function
to randomly fill the array with the numbers and a function to determine
if the array is a magic square. Run these functions for some large
number of times, say 1,000, 10,000, or 1,000,000, and see the number
of times the array is a magic square
*/



#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SIZE = 3;

//Function Prototype
void fillArr(int magicArr[][SIZE], int S);
bool findMagic(int magicArr[][SIZE], int S);


int main()
{
    srand(time(0));
    int magicArr[SIZE][SIZE];
    bool isMagicSquare;
    int i = 0;
    int j = 0;

    int loop = 0;
    int k = 0;
    cout << "How many squares do you want to generate? ";
    cin >> loop;

    while (k < loop)
    {
        fillArr(magicArr, SIZE);
        isMagicSquare = findMagic(magicArr, SIZE);

        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                cout << magicArr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        if (isMagicSquare)
        {
            cout << "!!!The 3x3 array IS A MAGIC SQUARE!!!" << endl;
        }
        else
        {
            cout << "The 3x3 array IS NOT a magic square." << endl;
        }
        cout << endl;
        k++;
    }




    return 0;
}



void fillArr(int magicArr[][SIZE], int S)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < S; i++)
    {
        for (j = 0; j < S; j++)
        {
            magicArr[i][j] = rand() % 10;
        }
    }

}


bool findMagic(int magicArr[][SIZE], int S)
{
    bool isMagic = false;
    int magicNum = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < S; i++)
    {
        for (j = 0; j < S; j++)
        {
            magicNum = magicNum + magicArr[i][j];
        }
    }

    magicNum = magicNum / 3;
    cout << "Magic number = " << magicNum << endl;

    //Check rows
    if ((magicArr[0][0] + magicArr[0][1] + magicArr[0][2] == magicNum) && (magicArr[1][0] + magicArr[1][1] + magicArr[1][2] == magicNum) && (magicArr[2][0] + magicArr[2][1] + magicArr[2][2] == magicNum))
    {
        isMagic = true;
    }
    else
    {
        return false;
    }

    //Check columns (new code)
    if ((magicArr[0][0] + magicArr[1][0] + magicArr[2][0] == magicNum) && (magicArr[0][1] + magicArr[1][1] + magicArr[2][1] == magicNum) && (magicArr[0][2] + magicArr[1][2] + magicArr[2][2] == magicNum))
    {
        isMagic = true;
    }
    else
    {
        return false;
    }

    //Check diagonals (new code)
    if ((magicArr[0][0] + magicArr[1][1] + magicArr[2][2] == magicNum) && (magicArr[0][2] + magicArr[1][1] + magicArr[2][0] == magicNum))
    {
        isMagic = true;
    }
    else
    {
        return false;
    }

    return isMagic;
}


/*
Sample Run 1
How many squares do you want to generate? 3
Magic number = 18
4 8 9
7 4 4
6 6 7

The 3x3 array IS NOT a magic square.

Magic number = 13
6 2 5
6 2 8
5 0 7

The 3x3 array IS NOT a magic square.

Magic number = 15
3 3 6
7 5 6
9 5 3

The 3x3 array IS NOT a magic square.


____________________________________________________
Sample Run 2
Magic number = 14
1 6 4
2 8 9
7 0 5

The 3x3 array IS NOT a magic square.

Magic number = 17
7 6 7
7 0 7
8 4 5

The 3x3 array IS NOT a magic square.

Magic number = 11
2 9 4
1 5 1
3 2 6

The 3x3 array IS NOT a magic square.

Magic number = 14
8 4 4
5 6 6
4 4 3

The 3x3 array IS NOT a magic square.


____________________________________________________
Sample Run 3
How many squares do you want to generate? 15
Magic number = 6
1 3 6
0 3 3
2 2 0

The 3x3 array IS NOT a magic square.

Magic number = 13
3 5 3
8 6 7
2 1 4

The 3x3 array IS NOT a magic square.

Magic number = 14
9 0 0
1 7 8
8 1 9

The 3x3 array IS NOT a magic square.

Magic number = 16
9 9 6
1 8 8
0 7 1

The 3x3 array IS NOT a magic square.

Magic number = 12
2 3 3
3 6 2
7 8 3

The 3x3 array IS NOT a magic square.

Magic number = 17
6 4 8
9 0 9
6 9 0

The 3x3 array IS NOT a magic square.

Magic number = 13
1 2 6
5 7 9
6 2 2

The 3x3 array IS NOT a magic square.

Magic number = 18
8 9 9
4 9 5
6 1 5

The 3x3 array IS NOT a magic square.

Magic number = 13
3 2 3
5 5 8
9 1 3

The 3x3 array IS NOT a magic square.

Magic number = 9
4 6 0
1 1 4
1 3 9

The 3x3 array IS NOT a magic square.

Magic number = 16
1 9 5
9 7 7
4 6 0

The 3x3 array IS NOT a magic square.

Magic number = 10
0 0 8
0 7 7
0 9 0

The 3x3 array IS NOT a magic square.

Magic number = 7
6 1 2
8 1 0
1 1 2

The 3x3 array IS NOT a magic square.

Magic number = 14
4 5 5
5 5 0
3 6 9

The 3x3 array IS NOT a magic square.

Magic number = 15
7 7 4
3 7 4
1 7 6

The 3x3 array IS NOT a magic square.

*/
