/*
Chapter 7 Programming Exercises Problem 1
Define an enumeration type triangleType that has the values scalene,
isosceles, equilateral, and noTriangle.

b. Write a function triangleShape that takes as parameters three numbers,
each of which represents the length of a side of the triangle. The function
should return the shape of the triangle. (Note: In a triangle, the sum of the
lengths of any two sides is greater than the length of the third side.)

c. Write a program that prompts the user to input the length of the sides
of a triangle and outputs the shape of the triangle.

*/


#include <iostream>
using namespace std;
enum triangleType {scalene, isosceles, equilateral, noTriangle};

triangleType triangleShape(int s1, int s2, int s3);

int main()
{

    triangleType shapeType;
    int side1 = 0;
    int side2 = 0;
    int side3 = 0;

    cout << "Enter the side lengths of a triangle: ";
    cin >> side1 >> side2 >> side3;

    shapeType = triangleShape(side1, side2, side3);

    cout << "The shape of the triangle is ";

    switch (shapeType)
    {
        case scalene:
            cout << "scalene" << endl;
            break;

        case isosceles:
            cout << "isosceles" << endl;
            break;

        case equilateral:
            cout << "equilateral" << endl;
            break;

        case noTriangle:
            cout << "not a triangle" << endl;
            break;

    }
    return 0;


}


triangleType triangleShape(int s1, int s2, int s3)
{
    triangleType shape;
    if (s1 + s2 < s3 || s1 + s3 < s2 || s2 + s3 < s1)
    {
        shape = noTriangle;
    }
    else if (s1 == s2 && s1 == s3 && s2 == s3)
    {
        shape = equilateral;
    }
    else if (s1 == s2 || s1 == s3 || s2 == s3)
    {
        shape = isosceles;
    }
    else
    {
        shape = scalene;
    }

    return shape;
}


/*
Sample Run 1
Enter the side lengths of a triangle: 4 7 10
The shape of the triangle is scalene

Sample Run 2
Enter the side lengths of a triangle: 7 7 9
The shape of the triangle is isosceles

Sample Run 3
Enter the side lengths of a triangle: 10 10 10
The shape of the triangle is equilateral
*/
