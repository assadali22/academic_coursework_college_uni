/*
Chapter 6 Programming Exercises Problem 15

During winter when it is very cold, typically, everyone would like to
know the windchill factor, especially, before going out. Meteorologists
use the following formula to compute the windchill factor, W:

W = 35.74 + (.6215 * T) - (35.75 * V^.16) + (.4275 * T * V^.16)

where V is the wind speed in miles per hour and T is the temperature
in degrees Fahrenheit. Write a program that prompts the user to input
the wind speed in miles per hour, and the temperature in degrees
Fahrenheit. The program then outputs the windchill factor.
Your program must contain at least two functions: one to get the user
input and the other to determine the windchill factor.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Function Prototype
void getTempAndWindSpeed(double& T, double& V);
double getWindChill(double T, double V);


int main()
{
    double temperature = 0;
    double windSpeed = 0;
    double windChill = 0;

    getTempAndWindSpeed(temperature, windSpeed);
    windChill = getWindChill(temperature, windSpeed);

    cout << fixed << showpoint << setprecision(2);
    cout << "The wind chill is: " << windChill << endl;
    return 0;

}

void getTempAndWindSpeed(double& T, double& V)
{
    cout << "Enter the temperature in Fahrenheit: ";
    cin >> T;

    cout << "Enter wind speed in miles per hour: ";
    cin >> V;
}


double getWindChill(double T, double V)
{
    double result;
    result = 35.74 + (.6215 * T) - (35.75 * pow(V, .16)) + (.4275 * T * pow(V, .16));
    return result;
}


/*
Sample Run 1
Enter the temperature in Fahrenheit: 43
Enter wind speed in miles per hour: 15
The wind chill is: 35.68


Sample Run 2
Enter the temperature in Fahrenheit: 28
Enter wind speed in miles per hour: 10
The wind chill is: 18.77

Sample Run 3
Enter the temperature in Fahrenheit: 38
Enter wind speed in miles per hour: 7
The wind chill is: 32.73
*/
