/*
Ch.4 Programming Exercises Problem 19

Ron bought several acres of farm to grow and sell vegetables. Suppose
that Ron wants to grow a maximum of two types of vegetables. Write
a program that prompts Ron or the user to do the following:
1. Enter the total farm area in acres.
2. The number of vegetables (one or two) that the user wants to grow.
3. If the user wants to grow two types of vegetables, then specify the portion,
as a percentage, of the farm land used for each type of vegetable.
4. Enter the seed cost, plantation cost, fertilizing cost, labor cost, for
each acre.
5. Enter vegetable selling price per acre.
6. Output the total revenue.
7. Output the profit/loss.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double farmArea = 0;
    int numOfVegetables = 0;
    double farmLandPercentage = 0;
    double pricePerAcre1 = 0;
    double pricePerAcre2 = 0;

    double seedCost1 = 0;
    double seedCost2 = 0;
    double plantationCost = 0;
    double fertilizingCost = 0;
    double laborCost = 0;

    double revenue = 0;
    double profit = 0;

    cout << "Enter farm area in acres: ";
    cin >> farmArea;

    cout << "Is one vegetable being planted or two? ";
    cin >> numOfVegetables;

    if (numOfVegetables == 2)
    {
        cout << "Enter percentage for how much the first vegetable will take up the land: ";
        cin >> farmLandPercentage;
    }
    else
    {
        farmLandPercentage = 100;
    }

    cout << "Enter seed cost for one vegetable per acre: ";
    cin >> seedCost1;

    cout << "Enter vegetable selling price per acre: ";
    cin >> pricePerAcre1;

    if (numOfVegetables == 2)
    {
        cout << "Enter seed cost for 2nd vegetable per acre: ";
        cin >> seedCost2;

        cout << "Enter 2nd vegetable selling price per acre: ";
        cin >> pricePerAcre2;
    }


    cout << "Enter plantation costs per acre: ";
    cin >> plantationCost;

    cout << "Enter fertilizing costs per acre: ";
    cin >> fertilizingCost;

    cout << "Enter labor costs per acre: ";
    cin >> laborCost;

    seedCost1 = seedCost1 * (farmArea * (farmLandPercentage / 100));
    seedCost2 = seedCost2 * (farmArea * (1 - (farmLandPercentage / 100)));

    plantationCost = farmArea * plantationCost;
    fertilizingCost = farmArea * fertilizingCost;
    laborCost = farmArea * laborCost;

    revenue = pricePerAcre1 * (farmArea * (farmLandPercentage / 100)) + pricePerAcre2 * (farmArea * (1 - (farmLandPercentage / 100)));
    profit = revenue - (seedCost1 + seedCost2 + plantationCost + fertilizingCost + laborCost);

    cout << fixed << showpoint << setprecision(2);
    cout << "Total Revenue: $" << revenue << endl;
    cout << "Profit/Loss: $" << profit << endl;
}

/*
Sample Run 1
Enter farm area in acres: 500
Is one vegetable being planted or two? 2
Enter percentage for how much the first vegetable will take up the land: 45
Enter seed cost for one vegetable per acre: 3.5
Enter vegetable selling price per acre: 2
Enter seed cost for 2nd vegetable per acre: 3
Enter 2nd vegetable selling price per acre: 6.5
Enter plantation costs per acre: 50
Enter fertilizing costs per acre: 35
Enter labor costs per acre: 70
Total Revenue: $2237.50
Profit/Loss: $-76875.00


Sample Run 2
Enter farm area in acres: 700
Is one vegetable being planted or two? 1
Enter seed cost for one vegetable per acre: 1.5
Enter vegetable selling price per acre: 50
Enter plantation costs per acre: 5
Enter fertilizing costs per acre: 10
Enter labor costs per acre: 20
Total Revenue: $35000.00
Profit/Loss: $9450.00


Sample Run 3
Enter farm area in acres: 1000
Is one vegetable being planted or two? 2
Enter percentage for how much the first vegetable will take up the land: 65
Enter seed cost for one vegetable per acre: 1.5
Enter vegetable selling price per acre: 75
Enter seed cost for 2nd vegetable per acre: 3.5
Enter 2nd vegetable selling price per acre: 90
Enter plantation costs per acre: 15
Enter fertilizing costs per acre: 15
Enter labor costs per acre: 25
Total Revenue: $80250.00
Profit/Loss: $23050.00
*/
