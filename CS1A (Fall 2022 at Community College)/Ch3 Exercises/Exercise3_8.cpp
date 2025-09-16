/*
Ch.3 Programming Exercises Problem 8

Linda is starting a new cosmetic and clothing business and would like
to make a net profit of approximately 10% after paying all the expenses,
which include merchandise cost, store rent, employees’ salary, and
electricity cost for the store. She would like to know how much the
merchandise should be marked up so that after paying all the expenses
at the end of the year she gets approximately 10% net profit on the
merchandise cost. Note that after marking up the price of an item
she would like to put the item on 15% sale.


Write a program that prompts Linda to enter the total cost of the
merchandise, the salary of the employees (including her own salary),
the yearly rent, and the estimated electricity cost. The program then
outputs how much the merchandise should be marked up so that Linda
gets the desired profit.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double merchCost = 0;
    double employeeSalary = 0;
    double lindaSalary = 0;
    double yearlyRent = 0;
    double electricityCost = 0;

    double markupPrice = 0;
    double profit = 0;

    cout << "Enter merchandise cost: ";
    cin >> merchCost;
    cout << endl;

    cout << "Enter employee salary: ";
    cin >> employeeSalary;
    cout << endl;

    cout << "Enter Linda's salary: ";
    cin >> lindaSalary;
    cout << endl;

    cout << "Enter yearly rent: ";
    cin >> yearlyRent;
    cout << endl;

    cout << "Enter electricity cost: ";
    cin >> electricityCost;
    cout << endl;

    markupPrice = (merchCost * 1.1) / .85;
    profit = (lindaSalary + markupPrice) - (electricityCost + yearlyRent + employeeSalary);

    cout << fixed << showpoint;
    cout << setprecision(2);
    if (profit < 0)
    {
        cout << "Profit is negative!" << endl;
    }
    else
    {
        cout << "To make profit, the merchandise needs to cost $" << markupPrice << endl;
    }

    return 0;
}


/*
Sample Run 1
Enter merchandise cost: 600

Enter employee salary: 450

Enter Linda's salary: 3000

Enter yearly rent: 600

Enter electricity cost: 250

To make profit, the merchandise needs to cost $776.47


Sample Run 2
Enter merchandise cost: 150

Enter employee salary: 75

Enter Linda's salary: 600

Enter yearly rent: 135

Enter electricity cost: 70

To make profit, the merchandise needs to cost $194.12


Sample Run 3
Enter merchandise cost: 200

Enter employee salary: 325

Enter Linda's salary: 250

Enter yearly rent: 400

Enter electricity cost: 150

Profit is negative!
*/
