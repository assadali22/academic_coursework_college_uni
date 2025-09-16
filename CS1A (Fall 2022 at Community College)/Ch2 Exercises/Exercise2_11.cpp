/*
Ch.2 Programming Exercises Problem 11
Write a program that prompts the capacity, in gallons, of an automobile
fuel tank and the miles per gallon the automobile can be driven.
The program outputs the number of miles the automobile can be driven
without refueling.
*/


#include <iostream>
using namespace std;

int main()
{
    int gallons = 0;
    int milesPerGallon = 0;
    int totalMiles = 0;

    cout << "Enter gasoline capacity in gallons: ";
    cin >> gallons;
    cout << endl;

    cout << "Enter the miles per gallon for the automobile: ";
    cin >> milesPerGallon;
    cout << endl;

    totalMiles = milesPerGallon * gallons;

    cout << "The total number of miles that can be driven is: " << totalMiles << endl;
    return 0;
}

//Output
/*
Sample Run 1
Enter gasoline capacity in gallons: 5

Enter the miles per gallon for the automobile: 30

The total number of miles that can be driven is: 150


Sample Run 2
Enter gasoline capacity in gallons: 4

Enter the miles per gallon for the automobile: 35

The total number of miles that can be driven is: 140


Sample Run 3
Enter gasoline capacity in gallons: 8

Enter the miles per gallon for the automobile: 40

The total number of miles that can be driven is: 320
*/
