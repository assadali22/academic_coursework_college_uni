/*
Purpose: This program uses dynamic arrays, both 1D and 2D, where
the user enters the number of elements for the arrays and populate
each array with a pointer that is pointing to an integer.
*/

#include <iostream>
using namespace std;
const int COL = 2;
//Function Prototypes
int* createInt();
void populate1D(int* arr, int n);
void populate2D(int** arr2D, int n);
void print1D(int* arr, int n);
void print2D(int** arr2D, int n);

int main()
{
    int elements;
    int *arr1D;
    int **arr2D;
    int rows;

    cout << "Enter the number of elements: ";
    cin >> elements;

    //1D array
    arr1D = new int[elements];

    //2D array
    if (elements % 2 == 0)
    {
        rows = elements / 2;
    }
    else
    {
        rows = (elements / 2) + 1;
    }
    arr2D = new int*[rows]; //create the rows

    for (int k = 0; k < rows; k++)
    {
        arr2D[k] = new int[COL];
    }

    //Populate
    cout << "Populating 1D Array" << endl;
    populate1D(arr1D, elements);

    cout << endl;
    cout << "Populating 2D Array" << endl;
    populate2D(arr2D, elements);

    //Print data
    print1D(arr1D, elements);
    cout << endl;
    print2D(arr2D, elements);

    delete [] arr1D;

    //9-18-2025 update: need for loop to deallocate dynamic 2D array
    for (int j = 0; j < rows; j++)
    {
        delete [] arr2D[j]; //delete columns
    }
    delete [] arr2D; //delete row and the dynamic 2D array
    return 0;

}


int* createInt()
{
    int *input = nullptr;
    input = new int;

    cout << "Enter an integer: ";
    cin >> *input;

    return input;
}


void populate1D(int* arr, int n)
{
    int i = 0;
    int *num;
    for (i = 0; i < n; i++)
    {
        num = createInt();
        arr[i] = *num;
    }
}

void populate2D(int** arr2D, int n)
{
    int i = 0;
    int j = 0;
    int *num;
    int rows;
    //Recompute n to be number of rows
    if (n % 2 == 0)
    {
        rows = n / 2;
    }
    else
    {
        rows = (n / 2) + 1;
    }

    for (i = 0; i < rows; i++) //cycle through rows
    {
        //cout << "i = " << i << endl;
        for (j = 0; j < COL; j++)
        {
            //cout << "j = " << j << endl;
            num = createInt();
            arr2D[i][j] = *num;
            n--;
            if (n == 0)
            {
                break;
            }
        }
    }

}


void print1D(int* arr, int n)
{
    int i = 0;
    cout << "1D Array:" << endl;
    cout << "[";
    for (i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1) //stops from putting a comma at the last element
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}


void print2D(int** arr2D, int n)
{
    int i = 0;
    int j = 0;
    int rows;

    //Calculate number of rows again
    if (n % 2 == 0)
    {
        rows = n / 2;
    }
    else
    {
        rows = (n / 2) + 1;
    }

    cout << "2D Array: " << endl;

    for (i = 0; i < rows; i++)
    {
        cout << "[";
        for (j = 0; j < COL; j++)
        {
            cout << arr2D[i][j];
            if (j < COL - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
}
