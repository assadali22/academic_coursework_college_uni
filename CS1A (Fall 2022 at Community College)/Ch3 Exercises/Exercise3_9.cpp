/*
Ch.3 Programming Exercises Problem 9
Dairy Farm decided to ship milk in containers in the form of cubes
rather than cylinders. Write a program that prompts the user to input
the radius of the base and the height of a cylindrical container and
outputs the side of the cube with the same volume as the
cylindrical container.

*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI = 3.141592;

int main()
{
    double radius = 0;
    double height = 0;

    double cylinderVolume = 0;
    double cubeSide = 0;

    cout << "Enter radius: ";
    cin >> radius;
    cout << endl;

    cout << "Enter height: ";
    cin >> height;
    cout << endl;

    cylinderVolume = PI * height * radius * radius;
    cubeSide = cbrt(cylinderVolume);

    cout << fixed << showpoint;
    cout << setprecision(2);

    cout << "The side of the cube that gives the same volume as the cylinder is " << cubeSide << endl;
    return 0;

}

/*
Sample Run 1
Enter radius: 8

Enter height: 5

The side of the cube that gives the same volume as the cylinder is 10.02


Sample Run 2
Enter radius: 6

Enter height: 4.5

The side of the cube that gives the same volume as the cylinder is 7.98


Sample Run 3
Enter radius: 20

Enter height: 15

The side of the cube that gives the same volume as the cylinder is 26.61
*/
