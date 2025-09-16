/*
Ch.4 Programming Exercises Problem 15

Write a program to implement the algorithm that you designed in
Exercise 22 of Chapter 1. (Assume that the account balance is stored
in the file Ch4_Ex15_Data.txt.) Your program should output account
balance before and after withdrawal and service charges. Also save the
account balance after withdrawal in the file Ch4_Ex15_Output.txt.
(exercise 20)

An ATM allows a customer to withdraw a maximum of $500 per day.
If a customer withdraws more than $300, the service charge is 4% of
the amount over $300. If the customer does not have sufficient money
in the account, the ATM informs the customer about the insufficient
funds and gives the customer the option to withdraw the money for a
service charge of $25.00.
If there is no money in the account or if the account balance is
negative, the ATM does not allow the customer to withdraw any money.
If the amount to be withdrawn is greater than $500, the ATM informs
the customer about the maximum amount that can be withdrawn.
*/

//The input data contains the number 450
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int option = 0;
    double accountBalance = 0;
    double userAmount = 0;
    double serviceCharge = 0;
    double amountWithdrawn = 0;
    double newBalance = 0;

    ifstream infile;
    ofstream outfile;

    infile.open("Ch4_Ex15_Data.txt");
    outfile.open("Ch4_Ex15_Output.txt");

    cout << "Enter amount to withdraw: ";
    cin >> userAmount;

    infile >> accountBalance;
    outfile << fixed << showpoint << setprecision(2);

    if (accountBalance < 0)
    {
        cout << "No money available in the account.";
    }

    else if (accountBalance < userAmount)
    {
        cout << "Insufficient funds. Withdraw anyway with $25 service charge? 1 = yes, 0 = no ";
        cin >> option;

        if (option == 1)
        {
            serviceCharge = 25;
            amountWithdrawn = userAmount;
            newBalance = accountBalance - userAmount;
        }
    }

    else if (userAmount > 300 && userAmount < 500)
    {
        serviceCharge = .04 * userAmount;
        amountWithdrawn = userAmount;
        newBalance = accountBalance - userAmount;
    }

    else if (userAmount > 500)
    {
        cout << "Only $500 can be withdrawn per day." << endl;
    }

    else if (0 < userAmount && userAmount <= 300)
    {
        amountWithdrawn = userAmount;
        newBalance = accountBalance - userAmount;
    }


    outfile << "Service charges: $" << serviceCharge << endl;
    outfile << "Amount withdrawn: $" << amountWithdrawn << endl;
    outfile << "Remaining account balance: $" << newBalance << endl;

    cout << "Finished processing to Ch4_Ex15_Output.txt." << endl;
    infile.close();
    outfile.close();
    return 0;
}
