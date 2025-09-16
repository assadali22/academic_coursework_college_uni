/*
Ch.2 Programming Exercises Problem 7
Write a program that prompts the user to input a decimal number and
outputs the number rounded to the nearest integer.
*/


#include <iostream>
using namespace std;


int main()
{
    double number = 0;

    cout << "Enter decimal number: ";
    cin >> number;
    cout << endl;

    cout << "The number rounded to the nearest integer is " << static_cast<int>(number) << endl;
    return 0;
}

//Outputs
/*
Sample Run 1
Enter decimal number: 2.3

The number rounded to the nearest integer is 2


Sample Run 2
Enter decimal number: 8.7

The number rounded to the nearest integer is 8


Sample Run 3
Enter decimal number: 77.6

The number rounded to the nearest integer is 77
*/
