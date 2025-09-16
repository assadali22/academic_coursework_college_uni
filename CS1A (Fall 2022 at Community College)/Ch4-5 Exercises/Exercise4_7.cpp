/*
Ch.4 Programming Exercises Problem 7

Write a program that prompts the user to input the value of a (the coefficient of x^2),
b (the coefficient of x), and c (the constant term) and outputs the
type of roots of the equation. If b^2 - 4ac >= 0, the program should output
the roots of the quadratic equation.

*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    double root1 = 0;
    double root2 = 0;
    double discriminant = 0;

    cout << "Enter the value of a from the quadratic equation: ";
    cin >> a;

    cout << "Enter the value of b: ";
    cin >> b;

    cout << "Enter the value of c: ";
    cin >> c;

    cout << fixed << showpoint;
    cout << setprecision(2);

    if ((b * b) - (4 * a * c) == 0)
    {
        root1 = -b / 2 * a;
        cout << "The quadratic equation has a double root, which is x = " << root1 << endl;
    }
    else if ((b * b) - (4 * a * c) > 0)
    {
        discriminant = sqrt((b * b) - (4 * a * c));
        root1 = (-b + discriminant) / (2 * a);
        root2 = (-b - discriminant) / (2 * a);
        cout << "The quadratic equation has 2 roots at x = " << root1 << " and x = " << root2 << endl;
    }
    else
    {
        cout << "The quadratic equation has complex roots." << endl;
    }
    return 0;
}

/*
Sample Run 1
Enter the value of a from the quadratic equation: 1
Enter the value of b: 0
Enter the value of c: -4
The quadratic equation has 2 roots at x = 2 and x = -2


Sample Run 2
Enter the value of a from the quadratic equation: 2
Enter the value of b: 6
Enter the value of c: -2
The quadratic equation has 2 roots at x = 0.30 and x = -3.30

Sample Run 3
Enter the value of a from the quadratic equation: 3
Enter the value of b: 7
Enter the value of c: 10
The quadratic equation has complex roots.
*/
