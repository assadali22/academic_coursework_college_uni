/*
Chapter 8 Programming Exercises Problem 5

Write a program that prompts the user to input a string and outputs the
string in uppercase letters. (Use a character array to store the string.)

*/

#include <iostream>
#include <ctype.h>
using namespace std;

const int SIZE = 25;

int main()
{
    char str[SIZE];
    int i = 0;

    cout << "Enter a string to be put into uppercase letters: ";
    cin >> str;


    while (str[i] != '\0')
    {
        str[i] = toupper(str[i]);
        i++;
    }


    cout << "The string with all letters uppercase: " << endl;

    i = 0;
    while (str[i] != '\0')
    {
        cout << str[i];
        i++;
    }

    return 0;

}

/*
Sample Run 1
Enter a string to be put into uppercase letters: sam
The string with all letters uppercase:
SAM


Sample Run 2
Enter a string to be put into uppercase letters: window
The string with all letters uppercase:
WINDOW


Sample Run 3
Enter a string to be put into uppercase letters: programming
The string with all letters uppercase:
PROGRAMMING

*/
