/*
Ch.5 Programming Exercises Problem 1

Write a program that prompts the user to input an integer and then
outputs both the individual digits of the number and the sum of the
digits. For example, it should output the individual digits of 3456 as
3 4 5 6, output the individual digits of 8030 as 8 0 3 0, output the
individual digits of 2345526 as 2 3 4 5 5 2 6, output the individual
digits of 4000 as 4 0 0 0, and output the individual digits of -2345
as 2 3 4 5.

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string numInt;
    char ch;
    int i = 0;
    int length = 0;

    cout << "Enter an integer: ";
    cin >> numInt;
    length = numInt.length();

    do
    {
        ch = numInt[i];
        cout << ch << " ";
        i++;
    }
    while (i < length);


    return 0;

}

/*
Sample Run 1
Enter an integer: 8625
8 6 2 5

Sample Run 2
Enter an integer: 61456
6 1 4 5 6

Sample Run 3
Enter an integer: 65244652
6 5 2 4 4 6 5 2
*/
