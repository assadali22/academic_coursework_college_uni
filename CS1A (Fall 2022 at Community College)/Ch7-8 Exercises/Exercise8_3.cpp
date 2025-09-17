/*
Chapter 8 Programming Exercises Problem 3

Write a C++ function, lastLargestIndex, that takes as parameters an
int array and its size and returns the index of the last occurrence of
the largest element in the array. Also, write a program to test
your function.

*/

#include <iostream>
using namespace std;
int lastLargestIndex(const int arr[], int S);
const int SIZE = 10;

int main()
{
    int arr[SIZE] = {5, 7, 29, 26, 23, 18, 22, 30, 17, 9};
    int largestIndex = 0;
    int i = 0;

    cout << "Here is the array: " << endl;
    for (i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    largestIndex = lastLargestIndex(arr, SIZE);

    if (largestIndex < 0)
    {
        cout << "No occurrence of the last index containing largest number. " << endl;
    }
    else
    {
        cout << "Last occurrence of largest element in array is in index " << largestIndex << ", which is " << arr[largestIndex] << endl;
    }

    return 0;
}



int lastLargestIndex(const int arr[], int S)
{
    int large = arr[0];
    int i = 0;
    int lastIndex = 0;

    for (i = 1; i < S; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
            lastIndex = i;
        }
    }

    return lastIndex;
}

/*
Sample Run 1
Here is the array:
5 7 29 26 23 18 22 30 17 9
Last occurrence of largest element in array is in index 7, which is 30
*/
