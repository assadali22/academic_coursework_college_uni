/*
Chapter 7 Programming Exercises Problem 11

Write a program that prompts the user to enter a string. The program outputs
the sum of the values (collating sequence or ASCII value) of the characters
in the string. For example, if the string is "spring", then the sum of
the values of the characters is 115 + 112 + 114 + 105 + 110 + 103 = 659.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string userInput;
    int strLength = 0;
    int i = 0;
    int sum = 0;

    cout << "Enter a string: ";
    cin >> userInput;

    strLength = userInput.length();

    for (i = 0; i < strLength; i++)
    {
        sum = sum + static_cast<int>(userInput[i]);
    }

    cout << "The sum of the characters in the string (ASCII) is: " << sum << endl;
    return 0;
}

/*
Sample Run 1
Enter a string: spring
The sum of the characters in the string (ASCII) is: 659


Sample Run 2
Enter a string: Sam
The sum of the characters in the string (ASCII) is: 289

Sample Run 3
Enter a string: VACATION
The sum of the characters in the string (ASCII) is: 597
*/
