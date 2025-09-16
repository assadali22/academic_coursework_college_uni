/*
Ch.3 Programming Exercises Problem 4
During each summer, John and Jessica grow vegetables in their backyard
and buy seeds and fertilizer from a local nursery. The nursery
carries different types of vegetable fertilizers in various bag sizes.
When buying a particular fertilizer, they want to know the price of
the fertilizer per pound and the cost of fertilizing per square foot.

The following program prompts the user to enter the size of the fertilizer
bag, in pounds, the cost of the bag, and the area, in square feet, that
can be covered by the bag. The program should output the desired
result. However, the program contains logic errors. Find and correct
the logic errors so that the program works properly.

*/


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double cost = 0;
    double area = 0;
    double bagSize = 0;
    double costPerPound = 0;
    double costPerSquareFoot = 0;

    cout << fixed << showpoint << setprecision(2);

    cout << "Enter the amount of fertilizer, in pounds, "
    << "in one bag: ";
    cin >> bagSize;
    cout << endl;

    cout << "Enter the cost of the " << bagSize
    << " pound fertilizer bag: ";
    cin >> cost;
    cout << endl;

    cout << "Enter the area, in square feet, that can be "
    << "fertilized by one bag: ";
    cin >> area;
    cout << endl;

    costPerPound = cost / bagSize;
    costPerSquareFoot = cost / area;

    cout << "The cost of the fertilizer per pound is: $"
    << costPerPound << endl;
    cout << "The cost of fertilizing per square foot is: $"
    << costPerSquareFoot << endl;

    return 0;
}

/*
Output with Logic Error:
Enter the amount of fertilizer, in pounds, in one bag: 8

Enter the cost of the 8.00 pound fertilizer bag: 12

Enter the area, in square feet, that can be fertilized by one bag: 30

The cost of the fertilizer per pound is: $0.67
The cost of fertilizing per square foot is: $2.50


Output without Logic Error:
Enter the amount of fertilizer, in pounds, in one bag: 8

Enter the cost of the 8.00 pound fertilizer bag: 12

Enter the area, in square feet, that can be fertilized by one bag: 30

The cost of the fertilizer per pound is: $1.50
The cost of fertilizing per square foot is: $0.40

*/
