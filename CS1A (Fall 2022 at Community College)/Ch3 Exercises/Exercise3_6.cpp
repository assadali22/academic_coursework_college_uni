/*
Ch.3 Programming Exercises Problem 6

Write a program that accepts as input the mass, in grams, and density,
in grams per cubic centimeters, and outputs the volume of the object
using the formula: volume = mass / density. Format your output to
two decimal places.

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double mass = 0;
    double density = 0;
    double volume = 0;

    cout << "Enter the object's mass: ";
    cin >> mass;
    cout << endl;

    cout << "Enter the object's density: ";
    cin >> density;
    cout << endl;

    volume = mass / density;

    cout << fixed << showpoint;
    cout << setprecision(2);

    cout << "The volume of the object is " << volume << endl;
    return 0;

}

/*
Sample Run 1
Enter the object's mass: 10

Enter the object's density: 34

The volume of the object is 0.29


Sample Run 2
Enter the object's mass: 85

Enter the object's density: 30

The volume of the object is 2.83


Sample Run 3
Enter the object's mass: 400

Enter the object's density: 34

The volume of the object is 11.76

*/
