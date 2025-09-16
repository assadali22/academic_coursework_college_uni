/*
Ch.6 Programming Exercises Problem 3

Write a program that prompts the user to input a sequence of characters
and outputs the number of vowels.

*/

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char& s);

int main()
{
    string userStr;
    int length = 0;
    int numVowels = 0;
    bool checkVowel;
    char ch;
    int i;

    cout << "Enter a sequence of characters: ";
    cin >> userStr;

    length = userStr.length();
    for (i = 0; i < length; i++)
    {
        ch = userStr[i];
        checkVowel = isVowel(ch);
        if (checkVowel)
        {
            numVowels++;
        }

    }

    cout << "Number of vowels: " << numVowels << endl;
    return 0;

}

bool isVowel(char& s)
{
    if (s == 'A' || s == 'a')
    {
        return true;
    }

    if (s == 'E' || s == 'e')
    {
        return true;
    }

    if (s == 'I' || s == 'i')
    {
        return true;
    }

    if (s == 'O' || s == 'o')
    {
        return true;
    }

    if (s == 'U' || s == 'u')
    {
        return true;
    }

    return false;

}

/*
Sample Run 1
Enter a sequence of characters: aodufba
Number of vowels: 4


Sample Run 2
Enter a sequence of characters: welcome
Number of vowels: 3

Sample Run 3
Enter a sequence of characters: computerScience
Number of vowels: 6
*/
