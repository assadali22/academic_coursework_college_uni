/*
Ch.4 Programming Exercises Problem 5

In a right triangle, the square of the length of one side is equal to the
sum of the squares of the lengths of the other two sides. Write a program
that prompts the user to enter the lengths of three sides of a
triangle and then outputs a message indicating whether the triangle is
a right triangle.

*/

#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int h = 0;

    cout << "Enter the length of one side for a triangle: ";
    cin >> a;

    cout << "Enter the length of the second side: ";
    cin >> b;

    cout << "Enter the length of the longest side: ";
    cin >> h;

    if ((a * a) + (b * b) == (h * h))
    {
        cout << "The triangle is a right triangle." << endl;
    }
    else
    {
        cout << "The triangle is not a right triangle." << endl;
    }
    return 0;
}


/*
Sample Run 1
Enter the length of one side for a triangle: 3
Enter the length of the second side: 4
Enter the length of the longest side: 5
The triangle is a right triangle.


Sample Run 2
Enter the length of one side for a triangle: 6
Enter the length of the second side: 8
Enter the length of the longest side: 10
The triangle is a right triangle.

Sample Run 3
Enter the length of one side for a triangle: 10
Enter the length of the second side: 8
Enter the length of the longest side: 14
The triangle is not a right triangle.
*/
