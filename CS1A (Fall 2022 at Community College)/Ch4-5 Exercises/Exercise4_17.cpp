/*
Ch.4 Programming Exercises Problem 17

Samantha and Vikas are looking to buy a house in a new development.
After looking at various models, the three models they like are
colonial, split-entry, and single-story. The builder gave them the base
price and the finished area in square feet of the three models. They
want to know the model(s) with the least price per square foot. Write
a program that accepts as input the base price and the finished area
in square feet of the three models. The program outputs the model(s)
with the least price per square foot.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double colonialArea = 0;
    double splitEntryArea = 0;
    double singleStoryArea = 0;

    double colonialPrice = 0;
    double splitEntryPrice = 0;
    double singleStoryPrice = 0;

    double colonialPricePerSqFt = 0;
    double splitEntryPricePerSqFt = 0;
    double singleStoryPricePerSqFt = 0;


    cout << "Enter area and price of colonial house: ";
    cin >> colonialArea >> colonialPrice;

    cout << "Enter area and price of split entry house: ";
    cin >> splitEntryArea >> splitEntryPrice;

    cout << "Enter area and price of single story house: ";
    cin >> singleStoryArea >> singleStoryPrice;


    colonialPricePerSqFt = colonialPrice / colonialArea;
    splitEntryPricePerSqFt = splitEntryPrice / splitEntryArea;
    singleStoryPricePerSqFt = singleStoryPrice / singleStoryArea;

    cout << fixed << showpoint;
    cout << setprecision(2);

    if (colonialPricePerSqFt < splitEntryPricePerSqFt && colonialPricePerSqFt < singleStoryPricePerSqFt)
    {
        cout << "Colonial house is cheapest at $" << colonialPricePerSqFt << " per square foot." << endl;
    }
    else if (splitEntryPricePerSqFt < colonialPricePerSqFt && splitEntryPricePerSqFt < singleStoryPricePerSqFt)
    {
        cout << "Split entry is cheapest at $" << splitEntryPricePerSqFt << " per square foot." << endl;
    }
    else if (singleStoryPricePerSqFt < colonialPricePerSqFt && singleStoryPricePerSqFt < splitEntryPricePerSqFt)
    {
        cout << "Single story house is cheapest at $" << singleStoryPricePerSqFt << " per square foot." << endl;
    }
    return 0;
}


/*
Sample Run 1
Enter area and price of colonial house: 1000 2500
Enter area and price of split entry house: 3000 4000
Enter area and price of single story house: 6000 7500
Single story house is cheapest at $1.25 per square foot.


Sample Run 2
Enter area and price of colonial house: 6500 7000
Enter area and price of split entry house: 5000 8400
Enter area and price of single story house: 8000 10500
Colonial house is cheapest at $1.08 per square foot.

Sample Run 3
Enter area and price of colonial house: 7800 9000
Enter area and price of split entry house: 11000 8500
Enter area and price of single story house: 8500 9250
Split entry is cheapest at $0.77 per square foot.
*/
