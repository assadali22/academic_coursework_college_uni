/*
Ch.3 Programming Exercises Problem 12

Two cars A and B leave an intersection at the same time. Car A travels
west at an average speed of x miles per hour and car B travels south at
an average speed of y miles per hour. Write a program that prompts the
user to enter the average speed of both the cars and the elapsed time
(in hours and minutes) and outputs the (shortest) distance between
the cars.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double speedCar1 = 0;
    double speedCar2 = 0;
    double hoursElapsed = 0;
    double minutesElapsed = 0;

    double distanceCar1 = 0;
    double distanceCar2 = 0;
    double shortestDistance = 0;

    cout << "Enter the speed of the first car in miles per hour: ";
    cin >> speedCar1;
    cout << endl;


    cout << "Enter the speed of the second car in miles per hour: ";
    cin >> speedCar2;
    cout << endl;


    cout << "Enter hours elapsed: ";
    cin >> hoursElapsed;
    cout << endl;


    cout << "Enter minutes elapsed: ";
    cin >> minutesElapsed;
    cout << endl;

    minutesElapsed = minutesElapsed / 60;
    hoursElapsed += minutesElapsed;

    distanceCar1 = hoursElapsed * speedCar1;
    distanceCar2 = hoursElapsed * speedCar2;
    shortestDistance = sqrt((distanceCar1 * distanceCar1) + (distanceCar2 * distanceCar2));

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "The shortest distance between the two cars is " << shortestDistance << endl;
    return 0;

}

/*
Sample Run 1
Enter the speed of the first car in miles per hour: 60

Enter the speed of the second car in miles per hour: 70

Enter hours elapsed: 2

Enter minutes elapsed: 45

The shortest distance between the two cars is 253.54


Sample Run 2
Enter the speed of the first car in miles per hour: 55

Enter the speed of the second car in miles per hour: 70

Enter hours elapsed: 6

Enter minutes elapsed: 30

The shortest distance between the two cars is 578.65


Sample Run 3
Enter the speed of the first car in miles per hour: 90

Enter the speed of the second car in miles per hour: 70

Enter hours elapsed: 3

Enter minutes elapsed: 0

The shortest distance between the two cars is 342.05

*/
