/*
Chapter 8 Programming Exercises Problem 19

(Airplane Seating Assignment) Write a program that can be used
to assign seats for a commercial airplane. The airplane has 13 rows,
with six seats in each row. Rows 1 and 2 are first class, rows 3 through
7 are business class, and rows 8 through 13 are economy class. Your
program must prompt the user to enter the following information:
a. Ticket type (first class, business class, or economy class)
b. Desired seat
Output the seating plan in the following form:

        A B C D E F
Row 1   * * X * X X
Row 2   * X * X * X
Row 3   * * X X * X
Row 4   X * X * X X
Row 5   * X * X * *
Row 6   * X * * * X
Row 7   X * * * X X
Row 8   * X * X X *
Row 9   X * X X * X
Row 10  * X * X X X
Row 11  * * X * X *
Row 12  * * X X * X
Row 13  * * * * X *
Here, * indicates that the seat is available; X indicates that the seat is
occupied. Make this a menu-driven program; show the user's choices
and allow the user to make the appropriate choices.

*/

#include <iostream>
using namespace std;
const int ROWS = 13;
const int COLUMNS = 6;

//Function Prototype
void getInput(int& ticket, int& userRow, char& userColumn);
bool isAvaliable(int ticket, int userRow, char userColumn, char seating[][COLUMNS], int R);
void showArr(char seating[][COLUMNS], int R);


int main()
{
    char seating[ROWS][COLUMNS] = {{'*', '*', 'X', '*', 'X', 'X'}, {'*', 'X', '*', 'X', '*', 'X'}, {'*', '*', 'X', 'X', '*', 'X'},
    {'X', '*', 'X', '*', 'X', 'X'}, {'*', 'X', '*', 'X', '*', '*'}, {'*', 'X', '*', '*', '*', 'X'}, {'X', '*', '*', '*', 'X', 'X'},
    {'*', 'X', '*', 'X', 'X', '*'}, {'X', '*', 'X', 'X', '*', 'X'}, {'*', 'X', '*', 'X', 'X', 'X'}, {'*', '*', 'X', '*', 'X', '*'},
    {'*', '*', 'X', 'X', '*', 'X'}, {'*', '*', '*', '*', 'X', '*'}};


    int ticketType = 0;
    int userRow = 0;
    char userColumn;
    int flag = 1;
    bool seatAvaliable = 0;
    showArr(seating, ROWS);
    cout << endl;
    cout << "Rows 1-2 are first class, Rows 3-7 are business class, Rows 8-13 are economy class." << endl;

    while (flag)
    {
        seatAvaliable = 0;
        getInput(ticketType, userRow, userColumn);
        seatAvaliable = isAvaliable(ticketType, userRow, userColumn, seating, ROWS);
        if (seatAvaliable)
        {
            cout << "Your seat has been confirmed!" << endl;
        }
        else
        {
            cout << "That seat is already occupied. Please select another seat." << endl;
        }
        cout << endl;
        showArr(seating, ROWS);

        cout << "Continue seat selection? 1 = yes, 0 = no: ";
        cin >> flag;
    }
    return 0;
}



void getInput(int& ticket, int& userRow, char& userColumn)
{
    cout << "Enter ticket type (1 = First Class, 2 = Business Class, 3 = Economy Class): ";
    cin >> ticket;

    cout << "Enter row of your seat choice ranging from 1-13: ";
    cin >> userRow;

    cout << "Enter column of your seat choice ranging from A-F: ";
    cin >> userColumn;
}


bool isAvaliable(int ticket, int userRow, char userColumn, char seating[][COLUMNS], int R)
{
    int columnIndex = 0;
    columnIndex = static_cast<int>(userColumn) - static_cast<int>('A');
    int i = 0;
    int j = 0;
    switch (ticket)
    {
    case 1:
        {
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < COLUMNS; j++)
                {
                    if (seating[i][j] == '*' && userRow == i + 1 && j == columnIndex)
                    {
                        seating[i][j] = 'X';
                        return true;
                    }
                }
            }
        }


    case 2:
        {
            for (i = 2; i < 7; i++)
            {
                for (j = 0; j < COLUMNS; j++)
                {
                    if (seating[i][j] == '*' && userRow == i + 1 && j == columnIndex)
                    {
                        seating[i][j] = 'X';
                        return true;
                    }
                }
            }
        }

    case 3:
        {
            for (i = 7; i < R; i++)
            {
                for (j = 0; j < COLUMNS; j++)
                {
                    if (seating[i][j] == '*' && userRow == i + 1 && j == columnIndex)
                    {
                        seating[i][j] = 'X';
                        return true;
                    }
                }
            }

        }


    }

    return false;
}


void showArr(char seating[][COLUMNS], int R)
{
    int i = 0;
    int j = 0;
    cout << "\tA B C D E F" << endl;
    for (i = 0; i < R; i++)
    {
        cout << "Row " << i + 1 << "\t";
        for (j = 0; j < COLUMNS; j++)
        {
            cout << seating[i][j] << " ";
        }
        cout << endl;
    }
}


/*
Sample Run 1
        A B C D E F
Row 1   * * X * X X
Row 2   * X * X * X
Row 3   * * X X * X
Row 4   X * X * X X
Row 5   * X * X * *
Row 6   * X * * * X
Row 7   X * * * X X
Row 8   * X * X X *
Row 9   X * X X * X
Row 10  * X * X X X
Row 11  * * X * X *
Row 12  * * X X * X
Row 13  * * * * X *

Rows 1-2 are first class, Rows 3-7 are business class, Rows 8-13 are economy class.
Enter ticket type (1 = First Class, 2 = Business Class, 3 = Economy Class): 1
Enter row of your seat choice ranging from 1-13: 2
Enter column of your seat choice ranging from A-F: E
Your seat has been confirmed!

        A B C D E F
Row 1   * * X * X X
Row 2   * X * X X X
Row 3   * * X X * X
Row 4   X * X * X X
Row 5   * X * X * *
Row 6   * X * * * X
Row 7   X * * * X X
Row 8   * X * X X *
Row 9   X * X X * X
Row 10  * X * X X X
Row 11  * * X * X *
Row 12  * * X X * X
Row 13  * * * * X *
Continue seat selection? 1 = yes, 0 = no: 0



Sample Run 2
        A B C D E F
Row 1   * * X * X X
Row 2   * X * X * X
Row 3   * * X X * X
Row 4   X * X * X X
Row 5   * X * X * *
Row 6   * X * * * X
Row 7   X * * * X X
Row 8   * X * X X *
Row 9   X * X X * X
Row 10  * X * X X X
Row 11  * * X * X *
Row 12  * * X X * X
Row 13  * * * * X *

Rows 1-2 are first class, Rows 3-7 are business class, Rows 8-13 are economy class.
Enter ticket type (1 = First Class, 2 = Business Class, 3 = Economy Class): 2
Enter row of your seat choice ranging from 1-13: 5
Enter column of your seat choice ranging from A-F: B
That seat is already occupied. Please select another seat.

        A B C D E F
Row 1   * * X * X X
Row 2   * X * X * X
Row 3   * * X X * X
Row 4   X * X * X X
Row 5   * X * X * *
Row 6   * X * * * X
Row 7   X * * * X X
Row 8   * X * X X *
Row 9   X * X X * X
Row 10  * X * X X X
Row 11  * * X * X *
Row 12  * * X X * X
Row 13  * * * * X *
Continue seat selection? 1 = yes, 0 = no: 1
Enter ticket type (1 = First Class, 2 = Business Class, 3 = Economy Class): 2
Enter row of your seat choice ranging from 1-13: 5
Enter column of your seat choice ranging from A-F: C
Your seat has been confirmed!

        A B C D E F
Row 1   * * X * X X
Row 2   * X * X * X
Row 3   * * X X * X
Row 4   X * X * X X
Row 5   * X X X * *
Row 6   * X * * * X
Row 7   X * * * X X
Row 8   * X * X X *
Row 9   X * X X * X
Row 10  * X * X X X
Row 11  * * X * X *
Row 12  * * X X * X
Row 13  * * * * X *
Continue seat selection? 1 = yes, 0 = no: 0



Sample Run 3
        A B C D E F
Row 1   * * X * X X
Row 2   * X * X * X
Row 3   * * X X * X
Row 4   X * X * X X
Row 5   * X * X * *
Row 6   * X * * * X
Row 7   X * * * X X
Row 8   * X * X X *
Row 9   X * X X * X
Row 10  * X * X X X
Row 11  * * X * X *
Row 12  * * X X * X
Row 13  * * * * X *

Rows 1-2 are first class, Rows 3-7 are business class, Rows 8-13 are economy class.
Enter ticket type (1 = First Class, 2 = Business Class, 3 = Economy Class): 3
Enter row of your seat choice ranging from 1-13: 11
Enter column of your seat choice ranging from A-F: A
Your seat has been confirmed!

        A B C D E F
Row 1   * * X * X X
Row 2   * X * X * X
Row 3   * * X X * X
Row 4   X * X * X X
Row 5   * X * X * *
Row 6   * X * * * X
Row 7   X * * * X X
Row 8   * X * X X *
Row 9   X * X X * X
Row 10  * X * X X X
Row 11  X * X * X *
Row 12  * * X X * X
Row 13  * * * * X *
Continue seat selection? 1 = yes, 0 = no: 0

*/
