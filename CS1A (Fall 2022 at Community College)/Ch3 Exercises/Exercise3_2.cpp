/*
Ch.3 Programming Exercises Problem 2

Consider the following program in which the statements are in the
incorrect order. Rearrange the statements so that the program prompts
the user to input the height and the radius of the base of a cylinder and
outputs the volume and surface area of the cylinder. Format the output
to two decimal places.

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.14159;


int main()
{
    double height;
    double radius;

    cout << "Enter the height of the cylinder: ";
    cin >> height;
    cout << endl;


    cout << "Enter the radius of the base of the cylinder: ";
    cin >> radius;
    cout << endl;

    cout << fixed << showpoint << setprecision(2);

    cout << "Volume of the cylinder = "
    << PI * pow(radius, 2.0) * height << endl;

    cout << "Surface area: "
    << 2 * PI * radius * height + 2 * PI * pow(radius, 2.0)
    << endl;


    return 0;
}

/*
Sample Run 1
Enter the height of the cylinder: 8

Enter the radius of the base of the cylinder: 5

Volume of the cylinder = 628.32
Surface area: 408.41


Sample Run 2
Enter the height of the cylinder: 10

Enter the radius of the base of the cylinder: 6

Volume of the cylinder = 1130.97
Surface area: 603.19


Sample Run 3
Enter the height of the cylinder: 4

Enter the radius of the base of the cylinder: 5

Volume of the cylinder = 314.16
Surface area: 282.74
*/
