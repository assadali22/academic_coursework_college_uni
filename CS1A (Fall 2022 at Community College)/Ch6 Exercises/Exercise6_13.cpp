/*
Chapter 6 Programming Exercises Problem 13

When you borrow money to buy a house, a car, or for some other purposes,
then you typically repay it by making periodic payments. Suppose
that the loan amount is L, r is the interest rate per year, m is the
number of payments in a year, and the loan is for t years. Suppose that
i = (r / m) and r is in decimal. Then the periodic payment is:

R = Li / 1 - (1 + i)^-mt

You can also calculate the unpaid loan balance after making certain
payments. For example, the unpaid balance after making k payments is:

L' = R[(1 - (1+i)^-(mt-k)) / i], R is periodic payment.

Write a program that prompts the user to input the values of L, r, m,
t, and k. The program then outputs the appropriate values. Your program
must contain at least two functions, with appropriate parameters,
to calculate the periodic payments and the unpaid balance after
certain payments. Make the program menu driven and use a loop so
that the user can repeat the program for different values.
*/



#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Function Prototypes
double findPeriodicPayment(double L, double m, double t, double r);
double findUnpaidBalance(double L, double r, double m, double t, double k);
void outputPayment(double L, double r, double m, double t, double k, double periodicPayment, double unpaidBalance);

int main()
{
    double LoanAmount = 0; //L
    double interestRate = 0; //r
    double numPaymentsPerYear = 0; //m
    double years = 0; //t
    double numPayments = 0; //k
    int option = 1;

    double periodicPayment = 0;
    double unpaidBalance = 0;

    while (option)
    {
        cout << "Enter loan amount: ";
        cin >> LoanAmount;

        cout << "Enter interest rate (ex. 5%): ";
        cin >> interestRate;

        cout << "Enter the number of payments in a year: ";
        cin >> numPaymentsPerYear;

        cout << "Enter length of loan in years: ";
        cin >> years;

        cout << "Enter number of payments to find unpaid balance: ";
        cin >> numPayments;


        periodicPayment = findPeriodicPayment(LoanAmount, numPaymentsPerYear, years, interestRate);
        unpaidBalance = findUnpaidBalance(LoanAmount, interestRate, numPaymentsPerYear, years, numPayments);
        outputPayment(LoanAmount, interestRate, numPaymentsPerYear, years, numPayments, periodicPayment, unpaidBalance);

        cout << "Repeat the program and test other values? 1 = yes, 0 = no: ";
        cin >> option;
        cout << endl;
        cout << endl;
    }

    return 0;
}



double findPeriodicPayment(double L, double m, double t, double r)
{
    double payment = 0;
    r = r / 100;
    double i = r / m;
    double temp = -1 * (m * t);

    payment = (L * i) / (1 - pow(1 + i, temp));
    return payment;
}


double findUnpaidBalance(double L, double r, double m, double t, double k)
{
    double result = 0;
    r = r / 100;
    double i = r / m;
    double temp = -1 * ((m * t) - k);

    result = (1 - pow(1 + i, temp)) / i;
    return result;

}



void outputPayment(double L, double r, double m, double t, double k, double periodicPayment, double unpaidBalance)
{
    cout << fixed << showpoint << setprecision(2);
    cout << endl;
    cout << "Loan Amount: $" << L << endl;
    cout << "Interest Rate: " << r << "%" << endl;
    cout << "Number of Payments Per Year: " << m << endl;
    cout << "Number of years: " << t << endl;
    cout << "Current Number of Payments: " << k << endl;
    cout << endl;

    cout << "Periodic Payment: $" << periodicPayment << endl;
    cout << "Unpaid Balance: $" << unpaidBalance << endl;


}

/*
Useless? Overthinking it? Nothing is done with result.
double unpaidPeriodicPayment(double result, double L, double r, int m, int t, int k)
{
    double balance = 0;
    r = r / 100;
    int i = r / m;
    int temp = m * t;

    balance = (L * i) / (1 - pow(1 + i, -temp));
    return balance;
}

*/

/*
Sample Run 1
Enter loan amount: 7000
Enter interest rate (ex. 5%): 4
Enter the number of payments in a year: 8
Enter length of loan in years: 10
Enter number of payments to find unpaid balance: 3

Loan Amount: $7000.00
Interest Rate: 4.00%
Number of Payments Per Year: 8.00
Number of years: 10.00
Current Number of Payments: 3.00

Periodic Payment: $106.38
Unpaid Balance: $63.78
Repeat the program and test other values? 1 = yes, 0 = no: 0


Sample Run 2
Enter loan amount: 15000
Enter interest rate (ex. 5%): 20
Enter the number of payments in a year: 12
Enter length of loan in years: 25
Enter number of payments to find unpaid balance: 6

Loan Amount: $15000.00
Interest Rate: 20.00%
Number of Payments Per Year: 12.00
Number of years: 25.00
Current Number of Payments: 6.00

Periodic Payment: $251.77
Unpaid Balance: $59.53
Repeat the program and test other values? 1 = yes, 0 = no: 0


Sample Run 3
Enter loan amount: 25400
Enter interest rate (ex. 5%): 12
Enter the number of payments in a year: 16
Enter length of loan in years: 25
Enter number of payments to find unpaid balance: 6

Loan Amount: $25400.00
Interest Rate: 12.00%
Number of Payments Per Year: 16.00
Number of years: 25.00
Current Number of Payments: 6.00

Periodic Payment: $200.60
Unpaid Balance: $126.31
Repeat the program and test other values? 1 = yes, 0 = no: 1


Enter loan amount: 22450
Enter interest rate (ex. 5%): 6
Enter the number of payments in a year: 12
Enter length of loan in years: 18
Enter number of payments to find unpaid balance: 9

Loan Amount: $22450.00
Interest Rate: 6.00%
Number of Payments Per Year: 12.00
Number of years: 18.00
Current Number of Payments: 9.00

Periodic Payment: $170.21
Unpaid Balance: $128.77
Repeat the program and test other values? 1 = yes, 0 = no: 0

*/
