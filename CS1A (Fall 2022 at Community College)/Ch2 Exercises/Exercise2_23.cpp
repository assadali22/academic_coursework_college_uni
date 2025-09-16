/*
Ch.2 Programming Exercises Problem 23

Cindy uses the services of a brokerage firm to buy and sell stocks. The
firm charges 1.5% service charges on the total amount for each transaction,
buy or sell. When Cindy sells stocks, she would like to know
if she gained or lost on a particular investment.
Write a program that allows Cindy to input the number of shares sold,
the purchase price of each share, and the selling price of each share.
The program outputs the amount invested, the total service charges,
amount gained or lost, and the amount received after selling the stock.
*/

#include <iostream>

using namespace std;

const double SERVICE_CHARGE = .015;

int main()
{
    int soldShares = 0;
    double purchasePrice = 0;
    double sellingPrice = 0;

    double amountInvested = 0;
    double totalCharges = 0;
    double totalAmount = 0;
    double amountAfterSale = 0;

    cout << "Enter number of shares sold: ";
    cin >> soldShares;
    cout << endl;

    cout << "Enter purchase price: ";
    cin >> purchasePrice;
    cout << endl;

    cout << "Enter selling price: ";
    cin >> sellingPrice;
    cout << endl;

    amountInvested = soldShares * purchasePrice;
    totalCharges = (SERVICE_CHARGE * purchasePrice) + (SERVICE_CHARGE * sellingPrice);
    amountAfterSale = sellingPrice * soldShares;
    totalAmount = amountAfterSale - amountInvested - totalCharges;

    cout << "Amount invested: $" << amountInvested << endl;
    cout << "Total charges: $" << totalCharges << endl;
    cout << "Profit/Loss: $" << totalAmount << endl;
    cout << "Amount after sale: $" << amountAfterSale << endl;
    return 0;
}

/*
Sample Run 1
Enter number of shares sold: 50

Enter purchase price: 2500

Enter selling price: 2250

Amount invested: $125000
Total charges: $71.25
Profit/Loss: $-12571.2
Amount after sale: $112500

Sample Run 2
Enter number of shares sold: 100

Enter purchase price: 3250

Enter selling price: 4000

Amount invested: $325000
Total charges: $108.75
Profit/Loss: $74891.2
Amount after sale: $400000


Sample Run 3
Enter number of shares sold: 45

Enter purchase price: 300

Enter selling price: 425

Amount invested: $13500
Total charges: $10.875
Profit/Loss: $5614.12
Amount after sale: $19125

*/
