/*
Ch.3 Programming Exercises Problem 7

Interest on a credit card’s unpaid balance is calculated using the
average daily balance. Suppose that netBalance is the balance shown
in the bill, payment is the payment made, d1 is the number of days in
the billing cycle, and d2 is the number of days payment is made before
billing cycle. Then, the average daily balance is:

averageDailyBalance = (netBalance * d1 – payment * d2) / d1

If the interest rate per month is, say, 0.0152, then the interest
on the unpaid balance is:

interest = averageDailyBalance * 0.0152

Write a program that accepts as input netBalance, payment, d1, d2,
and interest rate per month. The program outputs the interest. Format
your output to two decimal places.
*/


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double netBalance = 0;
    double payment = 0;
    int d1 = 0;
    int d2 = 0;

    double averageDailyBalance = 0;
    double interestRate = 0;
    double interest = 0;

    cout << "Enter net balance: ";
    cin >> netBalance;
    cout << endl;

    cout << "Enter the payment that was made: ";
    cin >> payment;
    cout << endl;

    cout << "Enter number of days in billing cycle: ";
    cin >> d1;
    cout << endl;

    cout << "Enter the number of days payment was made before billing cycle: ";
    cin >> d2;
    cout << endl;

    cout << "Enter interest rate: ";
    cin >> interestRate;
    cout << endl;

    averageDailyBalance = (netBalance * d1 - payment * d2) / d1;
    interest = averageDailyBalance * (interestRate / 100);

    cout << fixed << showpoint;
    cout << setprecision(2);

    cout << "The interest is: $" << interest << endl;
    return 0;
}

/*
Sample Run 1
Enter net balance: 10000

Enter the payment that was made: 65.25

Enter number of days in billing cycle: 30

Enter the number of days payment was made before billing cycle: 7

Enter interest rate: 5

The interest is: $499.24


Sample Run 2
Enter net balance: 4500

Enter the payment that was made: 12

Enter number of days in billing cycle: 60

Enter the number of days payment was made before billing cycle: 20

Enter interest rate: 3

The interest is: $134.88


Sample Run 3
Enter net balance: 6400

Enter the payment that was made: 25

Enter number of days in billing cycle: 45

Enter the number of days payment was made before billing cycle: 10

Enter interest rate: 6

The interest is: $383.67

*/
