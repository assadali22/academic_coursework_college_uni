/*
Ch.2 Programming Exercises Problem 19
Write a program that prompts the user to input the number of quarters,
dimes, and nickels. The program then outputs the total value of the
coins in pennies.
*/

#include <iostream>

using namespace std;

int main()
{
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    int quartersToPennies = 0;
    int dimesToPennies = 0;
    int nickelsToPennies = 0;
    int totalPennies = 0;

    cout << "Enter number of quarters: ";
    cin >> quarters;
    cout << endl;

    cout << "Enter number of dimes: ";
    cin >> dimes;
    cout << endl;

    cout << "Enter number of nickels: ";
    cin >> nickels;
    cout << endl;

    cout << "Enter number of pennies: ";
    cin >> pennies;
    cout << endl;

    quartersToPennies = quarters * 25;
    dimesToPennies = dimes * 10;
    nickelsToPennies = nickels * 5;
    totalPennies = quartersToPennies + dimesToPennies + nickelsToPennies + pennies;

    cout << "Total value of coins in pennies: " << totalPennies << " pennies" << endl;
    return 0;
}


/*
Sample Run 1
Enter number of quarters: 3

Enter number of dimes: 6

Enter number of nickels: 4

Enter number of pennies: 20

Total value of coins in pennies: 175 pennies


Sample Run 2
Enter number of quarters: 7

Enter number of dimes: 20

Enter number of nickels: 10

Enter number of pennies: 64

Total value of coins in pennies: 489 pennies


Sample Run 3
Enter number of quarters: 1

Enter number of dimes: 15

Enter number of nickels: 8

Enter number of pennies: 35

Total value of coins in pennies: 250 pennies

*/
