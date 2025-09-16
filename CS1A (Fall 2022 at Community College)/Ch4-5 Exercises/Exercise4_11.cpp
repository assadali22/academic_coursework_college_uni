/*
Ch.4 Programming Exercises Problem 11

Write a program that implements the algorithm given in Example 1-3
(Chapter 1), which determines the monthly wages of a salesperson.
*/

#include <iostream>
using namespace std;

int main()
{
    double baseSalary = 0;
    int noOfServiceYears = 0;
    double bonus = 0;
    double totalSales = 0;
    double additionalBonus = 0;
    double payCheck = 0;

    cout << "Enter base salary: ";
    cin >> baseSalary;

    cout << "Enter number of service years: ";
    cin >> noOfServiceYears;

    cout << "Enter total sales: ";
    cin >> totalSales;

    if (noOfServiceYears <= 5)
    {
        bonus = 10 * noOfServiceYears;
    }
    else
    {
        bonus = 20 * noOfServiceYears;
    }

    if (totalSales < 5000)
    {
        additionalBonus = 0;
    }
    else
    {
        if (totalSales >= 5000 && totalSales <= 10000)
        {
            additionalBonus = totalSales * .03;
        }
        else
        {
            additionalBonus = totalSales * .06;
        }
    }

    payCheck = baseSalary + bonus + additionalBonus;
    cout << "Monthly paycheck for salesperson is: " << payCheck << endl;
    return 0;
}

/*
Sample Run 1
Enter base salary: 15000
Enter number of service years: 6
Enter total sales: 50000
Monthly paycheck for salesperson is: 18120


Sample Run 2
Enter base salary: 25000
Enter number of service years: 8
Enter total sales: 145000
Monthly paycheck for salesperson is: 33860

Sample Run 3
Enter base salary: 30000
Enter number of service years: 11
Enter total sales: 20000
Monthly paycheck for salesperson is: 31420
*/
