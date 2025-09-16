/*
Ch.4 Programming Exercises Problem 23
The screen size of a TV is given by the length of the rectangular diagonal.
Traditional TVs come in 4:3 ratio, that is, the ratio of length to
width is 4 to 3. This means, if the length is x inches, then the width is
(3/4)x. LCD TVs come in 16:9 ratio. Write a program that prompts
the user to input the length of the diagonal (in inches) of the screen
and allows the user to select which type of TV’s screen length, screen
width, and screen area the user would like to calculate. Have the
program display the desired results.

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


const double widthRatioTraditional = .75;
const double widthRatioLCD = .5625;

int main()
{
    int option = 0;
    int tvType = 0;
    double diagonal = 0;
    double screenLength = 0;
    double screenWidth = 0;
    double screenArea = 0;
    double ratioSquared = 0;


    cout << "Enter length of diagonal: ";
    cin >> diagonal;

    cout << "Is the TV LCD (1) or traditional (2)? ";
    cin >> tvType;

    cout << "Do you want to find TV length (1), width (2), or area (3)? ";
    cin >> option;

    cout << fixed << showpoint;
    cout << setprecision(2);

    if (tvType == 1)
    {
        if (option == 1)
        {
            ratioSquared = widthRatioLCD * widthRatioLCD;
            screenLength = sqrt((diagonal * diagonal) / (1 + ratioSquared));
            cout << "The length of the TV is " << screenLength << " inches." << endl;
        }
        else if (option == 2)
        {
            ratioSquared = widthRatioLCD * widthRatioLCD;
            screenLength = sqrt((diagonal * diagonal) / (1 + ratioSquared));
            screenWidth = screenLength * widthRatioLCD;
            cout << "The width of the TV is " << screenWidth << " inches." << endl;
        }
        else if (option == 3)
        {
            ratioSquared = widthRatioLCD * widthRatioLCD;
            screenLength = sqrt((diagonal * diagonal) / (1 + ratioSquared));
            screenWidth = screenLength * widthRatioLCD;
            screenArea = screenLength * screenWidth;
            cout << "The area of the TV is " << screenArea << " square inches." << endl;
        }
    }


    if (tvType == 2)
    {
        if (option == 1)
        {
            ratioSquared = widthRatioTraditional * widthRatioTraditional;
            screenLength = sqrt((diagonal * diagonal) / (1 + ratioSquared));
            cout << "The length of the TV is " << screenLength << " inches." << endl;
        }
        else if (option == 2)
        {
            ratioSquared = widthRatioTraditional * widthRatioTraditional;
            screenLength = sqrt((diagonal * diagonal) / (1 + ratioSquared));
            screenWidth = screenLength * widthRatioTraditional;
            cout << "The width of the TV is " << screenWidth << " inches." << endl;
        }
        else if (option == 3)
        {
            ratioSquared = widthRatioTraditional * widthRatioTraditional;
            screenLength = sqrt((diagonal * diagonal) / (1 + ratioSquared));
            screenWidth = screenLength * widthRatioTraditional;
            screenArea = screenLength * screenWidth;
            cout << "The area of the TV is " << screenArea << " square inches." << endl;
        }
    }

    return 0;
}


/*
Sample Run 1
Enter length of diagonal: 30
Is the TV LCD (1) or traditional (2)? 1
Do you want to find TV length (1), width (2), or area (3)? 3
The area of the TV is 384.57 square inches.

Sample Run 2
Enter length of diagonal: 50
Is the TV LCD (1) or traditional (2)? 2
Do you want to find TV length (1), width (2), or area (3)? 2
The width of the TV is 30.00 inches.

Sample Run 3
Enter length of diagonal: 70
Is the TV LCD (1) or traditional (2)? 1
Do you want to find TV length (1), width (2), or area (3)? 1
The length of the TV is 61.01 inches.
*/
