/*
Ch.2 Programming Exercises Problem 17
Redo Programming Exercise 16 so that the user can also input the cost
of producing one liter of milk and the profit on each carton of milk.

A milk carton can hold 3.78 liters of milk. Each morning, a dairy farm
ships cartons of milk to a local grocery store.
Write a program that does the following:

a. Prompts the user to enter the total amount of milk produced in the
morning, the cost of producing one liter of milk, and the profit on
each carton of milk.
b. Outputs the number of milk cartons needed to hold milk. (Round
your answer to the nearest integer.)
c. Outputs the cost of producing milk.
d. Outputs the profit for producing milk.
*/

#include <iostream>
using namespace std;
const double CARTON_CAPACITY = 3.78;

int main()
{
    int milkProduced = 0;
    double literCost = 0;
    double profitPerCarton = 0;

    int numberOfCartons = 0;
    double totalCost = 0;
    double totalProfit = 0;

    cout << "Enter total amount of milk produced in liters: ";
    cin >> milkProduced;
    cout << endl;

    cout << "Enter the cost of producing one liter of milk: ";
    cin >> literCost;
    cout << endl;

    cout << "Enter the profit for each carton of milk: ";
    cin >> profitPerCarton;
    cout << endl;

    numberOfCartons = milkProduced / CARTON_CAPACITY;
    totalCost = literCost * CARTON_CAPACITY * numberOfCartons;
    totalCost = totalCost * 100;
    totalCost = static_cast<int>(totalCost);
    totalCost = totalCost / 100;

    totalProfit = (profitPerCarton * numberOfCartons * CARTON_CAPACITY) - totalCost;
    totalProfit = totalProfit * 100;
    totalProfit = static_cast<int>(totalProfit);
    totalProfit = totalProfit / 100;

    cout << "Number of milk cartons needed to hold milk: " << numberOfCartons << endl;
    cout << "Total cost: $" << totalCost << endl;
    cout << "Total profit: $" << totalProfit << endl;
    return 0;



}

/*
Sample Run 1
Enter total amount of milk produced in liters: 20

Enter the cost of producing one liter of milk: .38

Enter the profit for each carton of milk: .27

Number of milk cartons needed to hold milk: 5
Total cost: $7.18
Total profit: $-2.07


Sample Run 2
Enter total amount of milk produced in liters: 40

Enter the cost of producing one liter of milk: 2

Enter the profit for each carton of milk: 3.5

Number of milk cartons needed to hold milk: 10
Total cost: $75.59
Total profit: $56.7


Sample Run 3
Enter total amount of milk produced in liters: 50

Enter the cost of producing one liter of milk: .79

Enter the profit for each carton of milk: 2.5

Number of milk cartons needed to hold milk: 13
Total cost: $38.82
Total profit: $84.02
*/

