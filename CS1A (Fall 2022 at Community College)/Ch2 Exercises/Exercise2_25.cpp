/*
Ch.2 Programming Exercises Problem 25

Repeat Programming Exercise 24, but the wire is to be bent in the form
of a circle. In this case, the user specifies the length of the wire
and the program outputs the radius and area of the circle.
*/

#include <iostream>

using namespace std;
const double PI = 3.1416;

int main()
{
    double circumference = 0;
    double radius = 0;
    double area = 0;

    cout << "Enter the length of the wire: ";
    cin >> circumference;
    cout << endl;

    radius = circumference / (2 * PI);
    area = PI * radius * radius;

    cout << "The radius of the circle is: " << radius << endl;
    cout << "The area of the circle is " << area << endl;
    return 0;

}

/*
Sample Run 1
Enter the length of the wire: 7

The radius of the circle is: 1.11408
The area of the circle is 3.89929


Sample Run 2
Enter the length of the wire: 9.5

The radius of the circle is: 1.51197
The area of the circle is 7.18185


Sample Run 3
Enter the length of the wire: 24.7

The radius of the circle is: 3.93112
The area of the circle is 48.5493
*/
