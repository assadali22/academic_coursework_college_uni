/*
Ch.2 Programming Exercises Problem 13
To make a profit, a local store marks up the prices of its items by a certain
percentage. Write a program that reads the original price of the item
sold, the percentage of the marked-up price, and the sales tax rate.

The program then outputs the original price of the item, the percentage
of the mark-up, the store’s selling price of the item, the sales tax
rate, the sales tax, and the final price of the item. (The final price of the
item is the selling price plus the sales tax.)
*/


#include <iostream>
using namespace std;

int main()
{
    double originalPrice = 0;
    double markUpPercent = 0;
    double taxRate = 0;
    double storePrice = 0;
    double salesTax = 0;
    double finalPrice = 0;

    cout << "Program to calculate an item's final price after markup and sales tax.\n" << endl;
    cout << "Enter original price: ";
    cin >> originalPrice;
    cout << endl;

    cout << "Enter markup percentage: ";
    cin >> markUpPercent; //divide this by 100 along with tax
    cout << endl;

    cout << "Enter tax rate: ";
    cin >> taxRate;
    cout << endl;

    markUpPercent = markUpPercent / 100;
    taxRate = taxRate / 100;

    storePrice = originalPrice + (originalPrice * markUpPercent);
    salesTax = storePrice * taxRate;
    finalPrice = storePrice + salesTax;

    cout << "Original price: $" << originalPrice << endl;
    cout << "Markup percent: " << markUpPercent * 100  << "%" << endl;
    cout << "Store price: $" << storePrice << endl;
    cout << "Tax rate: " << taxRate * 100 << "%" << endl;
    cout << "Sales tax: $" << salesTax << endl;
    cout << "Final price: $" << finalPrice << endl;
    return 0;
}


/*
Sample Run 1
Program to calculate an item's final price after markup and sales tax.

Enter original price: 500

Enter markup percentage: 6

Enter tax rate: 4.5

Original price: $500
Markup percent: 6%
Store price: $530
Tax rate: 4.5%
Sales tax: $23.85
Final price: $553.85



Sample Run 2
Program to calculate an item's final price after markup and sales tax.

Enter original price: 2500

Enter markup percentage: 12

Enter tax rate: 6.8

Original price: $2500
Markup percent: 12%
Store price: $2800
Tax rate: 6.8%
Sales tax: $190.4
Final price: $2990.4


Sample Run 3
Program to calculate an item's final price after markup and sales tax.

Enter original price: 1950

Enter markup percentage: 10

Enter tax rate: 4.3

Original price: $1950
Markup percent: 10%
Store price: $2145
Tax rate: 4.3%
Sales tax: $92.235
Final price: $2237.24
*/
