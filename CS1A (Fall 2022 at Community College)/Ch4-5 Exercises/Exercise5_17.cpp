/*
Ch.5 Programming Exercises Problem 17

Write a program to implement the algorithm that you designed in
Exercise 19 of Chapter 1. Your program should allow the user to buy
as many items as the user desires.

*/

#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    int numOfItems = 0;
    int i;
    double itemPrice;
    double shippingFee = 0;
    double totalCost = 0;

    cout << "Enter the amount of items you wish to buy: ";
    cin >> numOfItems;

    for (i = 1; i <= numOfItems; i++)
    {
        cout << "Enter price of item #" << i << ": ";
        cin >> itemPrice;

        totalCost = totalCost + itemPrice;
    }

    if (totalCost < 200)
    {
        shippingFee = 10 * numOfItems;
        totalCost = totalCost + shippingFee;
    }

    cout << fixed << showpoint << setprecision(2);
    cout << "Total billing amount: $" << totalCost << endl;
    cout << "Shipping fees: $" << shippingFee << endl;
    return 0;
}

/*
Sample Run 1
Enter the amount of items you wish to buy: 3
Enter price of item #1: 50
Enter price of item #2: 60
Enter price of item #3: 70
Total billing amount: $210.00
Shipping fees: $30.00


Sample Run 2
Enter the amount of items you wish to buy: 8
Enter price of item #1: 34
Enter price of item #2: 21
Enter price of item #3: 6
Enter price of item #4: 78.5
Enter price of item #5: 62.3
Enter price of item #6: 11.8
Enter price of item #7: 32.6
Enter price of item #8: 12.25
Total billing amount: $258.45
Shipping fees: $0.00

Sample Run 3
Enter the amount of items you wish to buy: 7
Enter price of item #1: .5
Enter price of item #2: 6
Enter price of item #3: 58
Enter price of item #4: 12
Enter price of item #5: 6
Enter price of item #6: 32
Enter price of item #7: 22
Total billing amount: $206.50
Shipping fees: $70.00
*/
