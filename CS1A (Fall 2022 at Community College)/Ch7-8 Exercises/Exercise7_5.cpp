/*
Chapter 7 Programming Exercises Problem 5

Write a program that can be used to calculate the federal tax. The tax is
calculated as follows: For single people, the standard exemption is $4,000;
for married people, the standard exemption is $7,000. A person can also put
up to 6% of his or her gross income in a pension plan. The tax rates are as
follows: If the taxable income is:

$0-$15000, tax rate = 15%

$15001-$40000, 2250 + 25% of taxable income over $15K

Over $40000, 8460 + 35% of taxable income over $40K

Prompt the user to enter the following information:
-Marital status
-If the marital status is "married", ask for the number of children under
the age of 14
-Gross salary (If the marital status is "married" and both spouses have
income, enter the combined salary.)
-Percentage of gross income contributed to a pension fund
Your program must consist of at least the following functions:
a. Function getData: This function asks the user to enter the relevant
data.
b. Function taxAmount: This function computes and returns the tax owed.

To calculate the taxable income, subtract the sum of the standard exemption,
the amount contributed to a pension plan, and the personal exemption, which
is $1,500 per person. (Note that if a married couple has two children under the
age of 14, then the personal exemption is $1,500 * 4 = $6,000.)

*/

#include <iostream>
#include <iomanip>
using namespace std;


void getData(char& S, int& c, double& salary, double& fund);
double taxAmount(char S, int c, double salary, double fund);

const double SINGLE_EXEMPTION = 4000.00;
const double MARRIED_EXEMPTION = 7000.00;


int main()
{
    char martialStatus;
    int numOfChildren = 0;
    double grossSalary = 0;
    double pensionFund = 0;
    double tax = 0;

    getData(martialStatus, numOfChildren, grossSalary, pensionFund);
    tax = taxAmount(martialStatus, numOfChildren, grossSalary, pensionFund);

    cout << fixed << showpoint << setprecision(2);
    cout << "The taxed owed is $" << tax << endl;
    return 0;

}

void getData(char& S, int& c, double& salary, double& fund)
{
    cout << "Enter martial status (M = married, S = single): ";
    cin >> S;

    if (S == 'm' || S == 'M')
    {
        cout << "Enter the number of children under the age of 14: ";
        cin >> c;
    }

    cout << "Enter gross salary: ";
    cin >> salary;

    cout << "Enter percentage of gross income contributed to pension fund: ";
    cin >> fund;
}



double taxAmount(char S, int c, double salary, double fund)
{
    double taxableIncome = 0;
    double taxRate = 0;
    double taxOwed = 0;

    switch (S)
    {
        case 's':
        case 'S':
            taxableIncome = salary - (SINGLE_EXEMPTION + (salary * (fund / 100)) + 1500);
            break;

        case 'm':
        case 'M':
            taxableIncome = salary - (MARRIED_EXEMPTION + (salary * (fund / 100)) + (1500 * (c + 2)));
            break;

    }

    if (0 <= taxableIncome && taxableIncome <= 15000)
    {
        taxRate = .15;
        taxOwed = taxableIncome * taxRate;
        return taxOwed;

    }
    else if (15001 <= taxableIncome && taxableIncome <= 40000)
    {
        taxOwed = .25 * (taxableIncome + 2250);
        return taxOwed;
    }
    else if (taxableIncome > 40000)
    {
        taxOwed = .35 * (taxableIncome + 8460);
        return taxOwed;
    }

}

/*
Sample Run 1
Enter martial status (M = married, S = single): m
Enter the number of children under the age of 14: 2
Enter gross salary: 187500
Enter percentage of gross income contributed to pension fund: 4
The taxed owed is $61411.00


Sample Run 2
Enter martial status (M = married, S = single): s
Enter gross salary: 89000
Enter percentage of gross income contributed to pension fund: 1.5
The taxed owed is $31718.75

Sample Run 3
Enter martial status (M = married, S = single): m
Enter the number of children under the age of 14: 1
Enter gross salary: 104500
Enter percentage of gross income contributed to pension fund: 2
The taxed owed is $34779.50
*/
