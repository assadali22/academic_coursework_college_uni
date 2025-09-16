/*
Ch.2 Programming Exercises Problem 27
Modify Programming Exercise 26 so that the user can also specify the
area that can be painted with one gallon of paint.

A room has one door, two windows, and a built-in bookshelf and it needs
to be painted. Write a program that prompts the user to input the lengths and
widths of the door, each window, the bookshelf; and the length, width,
and height of the room (in feet). The program outputs the amount of
paint needed to paint the walls of the room.
*/

#include <iostream>

using namespace std;

int main()
{
    //Declaration
    double doorWidth = 0;
    double doorLength = 0;
    double doorArea = 0;

    double windowWidth1 = 0;
    double windowLength1 = 0;
    double windowArea1 = 0;

    double windowWidth2 = 0;
    double windowLength2 = 0;
    double windowArea2 = 0;

    double bookshelfWidth = 0;
    double bookshelfLength = 0;
    double bookshelfArea = 0;

    double roomWidth = 0;
    double roomLength = 0;
    double roomHeight = 0;
    double roomArea = 0;

    double sqFeetPerGallon = 0;
    double totalRoomArea = 0;
    double paintNeeded = 0;

    //Input
    cout << "Enter the width and length of the door: ";
    cin >> doorWidth >> doorLength;
    cout << endl;

    cout << "Enter the width and length of the first window: ";
    cin >> windowWidth1 >> windowLength1;
    cout << endl;

    cout << "Enter the width and length of the second window: ";
    cin >> windowWidth2 >> windowLength2;
    cout << endl;

    cout << "Enter the width and length of the bookshelf: ";
    cin >> bookshelfWidth >> bookshelfLength;
    cout << endl;

    cout << "Enter the width, length, and height of the room: ";
    cin >> roomWidth >> roomLength >> roomHeight;
    cout << endl;

    cout << "Enter the square feet that can be covered with one gallon of paint: ";
    cin >> sqFeetPerGallon;
    cout << endl;


    //Calculation
    doorArea = doorWidth * doorLength;
    windowArea1 = windowWidth1 * windowLength1;
    windowArea2 = windowWidth2 * windowLength2;
    bookshelfArea = bookshelfWidth * bookshelfLength;
    roomArea = (2 * roomWidth * roomLength) + (2 * roomWidth * roomHeight) + (2 * roomLength * roomHeight);
    totalRoomArea = roomArea - (doorArea + windowArea1 + windowArea2 + bookshelfArea);
    paintNeeded = totalRoomArea / sqFeetPerGallon;

    //Output
    cout << "The amount of paint needed to paint the room is " << paintNeeded << " gallons" << endl;
    return 0;
}


/*
Sample Run 1
Enter the width and length of the door: 8 7

Enter the width and length of the first window: 6 7

Enter the width and length of the second window: 6 7

Enter the width and length of the bookshelf: 12 12

Enter the width, length, and height of the room: 20 30 25

Enter the square feet that can be covered with one gallon of paint: 200

The amount of paint needed to paint the room is 17.08 gallons


Sample Run 2
Enter the width and length of the door: 12 10

Enter the width and length of the first window: 9 9

Enter the width and length of the second window: 9 16

Enter the width and length of the bookshelf: 6 8

Enter the width, length, and height of the room: 30 40 50

Enter the square feet that can be covered with one gallon of paint: 100

The amount of paint needed to paint the room is 90.07 gallons



Sample Run 3
Enter the width and length of the door: 15 10

Enter the width and length of the first window: 9 9

Enter the width and length of the second window: 9 9

Enter the width and length of the bookshelf: 7 15

Enter the width, length, and height of the room: 25 30 35

Enter the square feet that can be covered with one gallon of paint: 400

The amount of paint needed to paint the room is 12.3325 gallons
*/
