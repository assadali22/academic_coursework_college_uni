/*
Ch.4 Programming Exercises Problem 3

Write a program that prompts the user to input an integer between
0 and 35. If the number is less than or equal to 9, the program should
output the number; otherwise, it should output A for 10, B for 11, C for
12,...,and Z for 35. (Hint: Use the cast operator, static_cast<char>(),
for numbers >= 10.)

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int num = 0;
    char ch;
    cout << "Enter num: ";
    cin >> num;

    if (num <= 9)
    {
        cout << "Num is " << num << endl;
    }
    else if (num >= 10)
    {
        ch = static_cast<char>(num + 55); //offset by 55
        cout << "The letter corresponding to " << num << " is " << ch << endl;
    }
    return 0;
}

/*
Sample Run 1
Enter num: 5
Num is 5

Sample Run 2
Enter num: 66
The letter corresponding to 66 is B

Sample Run 3
Enter num: 100
The letter corresponding to 100 is d

Sample Run 4
Enter num: 10
The letter corresponding to 10 is A

Sample Run 5
Enter num: 11
The letter corresponding to 11 is B

*/
