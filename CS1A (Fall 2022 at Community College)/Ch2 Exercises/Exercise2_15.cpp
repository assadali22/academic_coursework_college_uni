/*
Ch.2 Programming Exercises Problem 15
Write a program to implement and test the algorithm that you designed for
Exercise 15 of Chapter 1. (Assume pi = 3.141593)

Given the radius, in inches, and price of a pizza, design an algorithm
to find the price of the pizza per square inch.
*/


#include <iostream>
using namespace std;

const double PI = 3.141593;

int main()
{
    double radius = 0;
    double pizzaPrice = 0;
    double pizzaArea = 0;
    double pricePerInch = 0;

    cout << "Enter the radius of the pizza: ";
    cin >> radius;
    cout << endl;

    cout << "Enter the price of the pizza: ";
    cin >> pizzaPrice;
    cout << endl;

    pizzaArea = PI * radius * radius;
    pricePerInch = pizzaPrice / pizzaArea;

    pricePerInch = pricePerInch * 100;
    pricePerInch = static_cast<int>(pricePerInch);
    pricePerInch = pricePerInch / 100.0;

    cout << "The price of the pizza for one square inch is $" << pricePerInch << endl;
    return 0;
}


/*
Sample Run 1
Enter the radius of the pizza: 3

Enter the price of the pizza: 7.5

The price of the pizza for one square inch is $0.26


Sample Run 2
Enter the radius of the pizza: 9

Enter the price of the pizza: 8

The price of the pizza for one square inch is $0.03


Sample Run 3
Enter the radius of the pizza: 5

Enter the price of the pizza: 12

The price of the pizza for one square inch is $0.15

*/
