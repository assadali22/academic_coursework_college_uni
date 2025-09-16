/*
Ch.2 Programming Exercises Problem 21
Newton's Law Of Gravitation:
Write a program that prompts the user to input the masses of the
bodies and the distance between the bodies. The program then
outputs the force between the bodies.

k = 6.67 * 10^-8 (0.0000000667)
*/


#include <iostream>

using namespace std;

const double K = 0.0000000667;

int main()
{
    double massOne = 0;
    double massTwo = 0;
    double distance = 0;
    double force = 0;

    cout << "Enter the mass of the first body: ";
    cin >> massOne;
    cout << endl;

    cout << "Enter the mass of the second body: ";
    cin >> massTwo;
    cout << endl;

    cout << "Enter the distance between the two bodies: ";
    cin >> distance;
    cout << endl;

    force = K * ((massOne * massTwo) / (distance * distance));

    cout << "The gravitational force is " << force << endl;
    return 0;
}



/*
Sample Run 1
Enter the mass of the first body: 7500

Enter the mass of the second body: 3400

Enter the distance between the two bodies: 15000

The gravitational force is 7.55933e-009


Sample Run 2
Enter the mass of the first body: 10000

Enter the mass of the second body: 25000

Enter the distance between the two bodies: 100000

The gravitational force is 1.6675e-009


Sample Run 3
Enter the mass of the first body: 12500

Enter the mass of the second body: 7400

Enter the distance between the two bodies: 2000

The gravitational force is 1.54244e-006

*/
