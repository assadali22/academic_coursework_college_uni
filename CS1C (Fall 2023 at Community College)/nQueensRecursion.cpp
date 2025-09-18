#include <iostream>
using namespace std;
//Queens Recursive Algorithm 4x4 board (no queen can kill another)

//Function Prototypes
bool solveQueen(char** board, int bSize, int col);
bool isValid(char** board, int bSize, int row, int col);
void printBoard(char** board, int s);

int main()
{
    int boardSize = 0;
    cout << "Enter board size: ";
    cin >> boardSize;

    char** board = nullptr;

    //create the board
    board = new char*[boardSize]; //create rows of boards
    for (int i = 0; i < boardSize; i++)
    {
        board[i] = new char[boardSize]; //make the columns
    }

    for (int r = 0; r < boardSize; r++)
    {
        for (int c = 0; c < boardSize; c++)
        {
            board[r][c] = '-';
        }
    }



    if (!solveQueen(board, boardSize, 0))
    {
        cout << "There is no solution to n queens problem with the specified size." << endl;
    }

    /*
    if (!solveQueen(board, boardSize, 0))
    {
        cout << "There is no solution to n queens problem with the specified size." << endl;
    }
    else
    {
        printBoard(board, boardSize);
    }
    */


    //clean up array (deallocate)
    for (int i = 0; i < boardSize; i++)
    {
        delete [] board[i];
    }

    delete [] board;


    return 0;
}



bool solveQueen(char** board, int bSize, int col)
{
    if (col == bSize)
    {
        printBoard(board, bSize);
        return true;
    }

    for (int row = 0; row < bSize; row++)
    {
        if (isValid(board, bSize, row, col))
        {
            board[row][col] = 'Q';


            if (solveQueen(board, bSize, col + 1))
            {
                return true;
            }

            board[row][col] = '-';

        }


    }

    return false;
}


bool isValid(char** board, int bSize, int row, int col)
{
    //check row, in the direction to the left
    for (int c = col - 1; c >= 0; c--)
    {
        if (board[row][c] == 'Q')
        {
            return false;
        }
    }


    //check diagonal going up
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }

    //check diagonal going down
    for (int r = row + 1, c = col - 1; r < bSize && c >= 0; r++, c--)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
    }

    return true;

}


void printBoard(char** board, int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}
