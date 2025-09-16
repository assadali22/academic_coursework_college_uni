/*
Ch.3 Programming Exercises Problem 11

A size of a jumbo candy bar with rectangular shape is l X w X h. Due
to rising costs of coca, the volume of the candy bar is to be reduced by
p%. To accomplish this, the management decided to keep the thickness,
h, of the candy bar the same, and reduce the length and width
by the same amount. For example, if l = 12, w = 7, h = 3, and p = 10,
then the new dimension of the candy bar is 11.39 X 6.64 X 3. Write a
program to accomplish this.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double reductionPercent = 0;
    double length = 0;
    double width = 0;
    double height = 0;

    cout << "Enter candy bar length: ";
    cin >> length;
    cout << endl;

    cout << "Enter candy bar width: ";
    cin >> width;
    cout << endl;

    cout << "Enter candy bar height: ";
    cin >> height;
    cout << endl;

    cout << "Enter reduction percent for the volume of the candy: ";
    cin >> reductionPercent;
    cout << endl;

    cout << "Original dimensions: L = " << length << ", W = " << width << ", H = " << height << endl;

    reductionPercent = reductionPercent / 200;
    length = length - (length * reductionPercent);
    width = width - (width * reductionPercent);

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "New dimensions: L = " << length << ", W = " << width << ", H = " << height << endl;
    return 0;

}

/*
Sample Run 1
Enter candy bar length: 12

Enter candy bar width: 7

Enter candy bar height: 3

Enter reduction percent for the volume of the candy: 10

Original dimensions: L = 12, W = 7, H = 3
New dimensions: L = 11.40, W = 6.65, H = 3.00


Sample Run 2
Enter candy bar length: 15

Enter candy bar width: 13

Enter candy bar height: 9

Enter reduction percent for the volume of the candy: 25

Original dimensions: L = 15, W = 13, H = 9
New dimensions: L = 13.12, W = 11.38, H = 9.00


Sample Run 3
Enter candy bar length: 9

Enter candy bar width: 6

Enter candy bar height: 8

Enter reduction percent for the volume of the candy: 20

Original dimensions: L = 9, W = 6, H = 8
New dimensions: L = 8.10, W = 5.40, H = 8.00

*/
