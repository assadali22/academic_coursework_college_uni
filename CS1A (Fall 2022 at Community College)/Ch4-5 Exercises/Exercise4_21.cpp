/*
Ch.4 Programming Exercises Problem 21

Write a program that prompts the user two points in the x-y plane.
The program outputs the equation of the line and uses if statements
to determine and output whether the line is vertical, horizontal,
increasing, or decreasing. If l is a non-vertical line,
output its equation in the form y = mx + b
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double y1 = 0, y2 = 0;
    double x1 = 0, x2 = 0;
    double m = 0, b = 0;

    cout << "Enter first point in xy plane: ";
    cin >> x1 >> y1;

    cout << "Enter second point in xy plane: ";
    cin >> x2 >> y2;


    m = (y2 - y1) / (x2 - x1);
    cout << fixed << showpoint;
    cout << setprecision(2);

    if (m > 0)
    {
        cout << "The line is increasing." << endl;
        b = y1 - (m * x1);
        cout << "y = " << m << "x + " << b << endl;
    }
    else if (m < 0)
    {
        cout << "The line is decreasing." << endl;
        b = y1 - (m * x1);
        cout << "y = " << m << "x + " << b << endl;
    }
    else if (m == 0)
    {
        cout << "The line is horizontal." << endl;
        b = y1 - (m * x1);
        cout << "y = " << b << endl;
    }
    else
    {
        cout << "The line is vertical." << endl;
    }
    return 0;
}

/*
Sample Run 1
Enter first point in xy plane: 3 5
Enter second point in xy plane: 6 7
The line is increasing.
y = 0.67x + 3.00

Sample Run 2
Enter first point in xy plane: 10 2
Enter second point in xy plane: 4 8
The line is decreasing.
y = -1.00x + 12.00

Sample Run 3
Enter first point in xy plane: 4 8
Enter second point in xy plane: 2 8
The line is horizontal.
y = 8.00

*/
