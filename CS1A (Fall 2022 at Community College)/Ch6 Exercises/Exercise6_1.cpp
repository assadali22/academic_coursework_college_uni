/*
Ch.6 Programming Exercises Problem 1

Write a program that uses the function isPalindrome given in Example
6-6 (Palindrome). Test your program on the following strings:
"madam", "abba", "22", "67876", "444244", and "trymeuemyrt"

b. Modify the function isPalindrome of Example 6-6 so that when
determining whether a string is a palindrome, cases are ignored,
that is, uppercase and lowercase letters are considered the same.
(A string is a palindrome if it reads forward and backward in the
same way)

*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main()
{
    bool palindrome;
    string input;

    cout << "Enter a string: ";
    cin >> input;


    palindrome = isPalindrome(input);

    if (palindrome)
    {
        cout << input << " is a palindrome." << endl;
    }
    else
    {
        cout << input << " is not a palindrome." << endl;
    }
    return 0;

}


bool isPalindrome(string str)
{
    int length = str.length();
    char temp;
    for (int i = 0; i < length / 2; i++)
    {
        temp = str[length - 1 - i];
        if (str[i] != temp && static_cast<int>(str[i]) - static_cast<int>('A') == static_cast<int>(temp))
        {
            return false;
        }
    }

    return true;
}


/*
OUTPUT:

Enter a string: madam
madam is a palindrome.


Enter a string: abba
abba is a palindrome.


Enter a string: 22
22 is a palindrome.


Enter a string: 67876
67876 is a palindrome.


Enter a string: 444244
444244 is not a palindrome.

Enter a string: trymeuemyrt
trymeuemyrt is a palindrome.

Cases ignored, upper and lower don't matter:
Enter a string: MadAm
MadAm is a palindrome.


Enter a string: aBbA
aBbA is a palindrome.


Enter a string: tRymEeuEmyrT
tRymEeuEmyrT is a palindrome.
*/
