/*
Ch.2 Programming Exercises Problem 29
A contractor orders, say, 30 cubic yards of premixed concrete to construct
a patio that is to be, say, four inches thick. The length of the patio
is to be, say, twice the width. Write a program that prompts the user
to specify the amount of premixed concrete (in cubic yards) ordered,
the thickness of the patio (in inches), and the ratio of length and width.
The program then outputs the length and width of the patio (in feet).
(1 cubic yard = 27 cubic feet.)
*/


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double concreteAmount = 0; //This is volume
    double patioThickness = 0; //This is the height
    double patioRatio = 0;

    double length = 0;
    double width = 0;

    cout << "Enter amount of premixed concrete in cubic yards: ";
    cin >> concreteAmount;
    cout << endl;


    cout << "Enter patio thickness in inches: ";
    cin >> patioThickness;
    cout << endl;


    cout << "Enter the ratio between length and width: ";
    cin >> patioRatio;
    cout << endl;

    concreteAmount = concreteAmount * 27;
    patioThickness = patioThickness / 12;
    width = sqrt(concreteAmount / (patioRatio * patioThickness));
    length = width * patioRatio;

    cout << "The patio length is " << length << " inches and the patio width is " << width << " inches." << endl;
    return 0;
}

/*
Sample Run 1
Enter amount of premixed concrete in cubic yards: 30

Enter patio thickness in inches: 4

Enter the ratio between length and width: 2

The patio length is 69.7137 inches and the patio width is 34.8569 inches.


Sample Run 2
Enter amount of premixed concrete in cubic yards: 400

Enter patio thickness in inches: 6

Enter the ratio between length and width: .5

The patio length is 103.923 inches and the patio width is 207.846 inches.


Sample Run 3
Enter amount of premixed concrete in cubic yards: 250

Enter patio thickness in inches: 12

Enter the ratio between length and width: 3

The patio length is 142.302 inches and the patio width is 47.4342 inches.
*/
