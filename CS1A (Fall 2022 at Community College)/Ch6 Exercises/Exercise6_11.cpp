/*
Chapter 6 Programming Exercises Problem 11

The following formula gives the distance between two points (x1, y1)
and (x2, y2) in the Cartesian plane:

sqrt((x2-x1)^2 + (y2-y1)^2)
Given the center and a point on the circle, you can use this formula to
find the radius of the circle. Write a program that prompts the user to
enter the center and a point on the circle. The program should then
output the circle's radius, diameter, circumference, and area. Your program
must have at least the following functions:

distance: This function takes as its parameters four numbers that represent
two points in the plane and returns the distance between them.

radius: This function takes as its parameters four numbers that
represent the center and a point on the circle, calls the function
distance to find the radius of the circle, and returns the
circle's radius.

circumference: This function takes as its parameter a number
that represents the radius of the circle and returns the
circle's circumference.

area: This function takes as its parameter a number that represents
the radius of the circle and returns the circle's area.

*/


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.1416;

double getRadius(int x1, int y1, int x2, int y2);
double getDistance(int x1, int y1, int x2, int y2);
double getCircumference(double radius);
double getArea(double radius);
void showCircleData(double radius, double circumference, double area);


int main()
{
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    double radius = 0;
    double circumference = 0;
    double area = 0;

    cout << "Enter the coordinates of the center of the circle: ";
    cin >> x1 >> y1;

    cout << "Enter the coordinates of a point on the circle: ";
    cin >> x2 >> y2;

    radius = getRadius(x1, y1, x2, y2);
    circumference = getCircumference(radius);
    area = getArea(radius);

    showCircleData(radius, circumference, area);
    return 0;

}


double getRadius(int x1, int y1, int x2, int y2)
{
    double r;
    r = getDistance(x1, y1, x2, y2);

    return r;
}


double getDistance(int x1, int y1, int x2, int y2)
{
    double d;
    double x;
    double y;

    x = (x2 - x1) * (x2 - x1);
    y = (y2 - y1) * (y2 - y1);
    d = sqrt(x + y);

    return d;
}


double getCircumference(double radius)
{
    double c;
    c = 2 * PI * radius;

    return c;
}


double getArea(double radius)
{
    double a;
    a = PI * radius * radius;

    return a;
}


void showCircleData(double radius, double circumference, double area)
{
    cout << fixed << showpoint << setprecision(2);
    cout << "The radius is: " << radius << endl;
    cout << "The diameter is: " << radius * 2 << endl;
    cout << "The circumference is: " << circumference << endl;
    cout << "The area is: " << area << endl;

}


/*
Sample Run 1
Enter the coordinates of the center of the circle: 2 4
Enter the coordinates of a point on the circle: -5 8
The radius is: 8.06
The diameter is: 16.12
The circumference is: 50.66
The area is: 204.20

Sample Run 2
Enter the coordinates of the center of the circle: -6 3
Enter the coordinates of a point on the circle: 4 5
The radius is: 10.20
The diameter is: 20.40
The circumference is: 64.08
The area is: 326.73

Sample Run 3
Enter the coordinates of the center of the circle: 6 4
Enter the coordinates of a point on the circle: -2 1
The radius is: 8.54
The diameter is: 17.09
The circumference is: 53.68
The area is: 229.34
*/
