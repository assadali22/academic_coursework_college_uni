/*
Chapter 8 Programming Exercises Problem 11

(Adding Large Integers) In C++, the largest int value is 2147483647.
So, an integer larger than this cannot be stored and processed as
an integer. Similarly, if the sum or product of two positive integers
is greater than 2147483647, the result will be incorrect. One way to
store and manipulate large integers is to store each individual digit
of the number in an array.
Write a program that inputs two positive integers of, at most,
20 digits and outputs the sum of the numbers. If the sum of the
numbers has more than 20 digits, output the sum with an appropriate
message. Your program must, at least, contain a function
to read and store a number into an array and another function to
output the sum of the numbers. (Hint: Read numbers as strings and
store the digits of the number in the reverse order.)

84516 -> 61548
3456 ->  6543

add from left to right
 61548
+6543
-------
=27978, which then reverses and becomes 87,972, which is 84516 + 3456

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//Function Prototypes
void readNumsFillVector(string &num1, string &num2, vector<int> &n1, vector<int> &n2);
void addNumbers(vector<int> &n1, vector<int> &n2, vector<int> &result);
void printSum(vector<int> r);

int main()
{
    string num1;
    string num2;
    vector<int> n1; //digit array for num1
    vector<int> n2; //digit array for num2
    readNumsFillVector(num1, num2, n1, n2);


    vector<int> result;
    addNumbers(n1, n2, result);
    printSum(result);

    return 0;

}

void printSum(vector<int> r)
{
    reverse(r.begin(), r.end()); //reverse to get the actual result

    if (r.size() > 20)
        cout << "Resulting sum has overflow, greater than 20 digits" << endl;

    cout << "Sum = ";
    for (int index = 0; index < r.size(); index++)
    {
        cout << r[index];
    }
}

void addNumbers(vector<int> &n1, vector<int> &n2, vector<int> &result)
{
    int maxLength = max(n1.size(), n2.size());
    int sum;
    int carry = 0;
    int digit1, digit2;

    for (int j = 0; j < maxLength; j++)
    {
        //Two numbers may have different number of digits.
        //Check that if j is still in bounds within the vector index
        //that contains a digit, use the digit, else the digit is 0.

        if (j < n1.size())
            digit1 = n1[j];
        else
            digit1 = 0;

        if (j < n2.size())
            digit2 = n2[j];
        else
            digit2 = 0;

        sum = digit1 + digit2 + carry;
        result.push_back(sum % 10); //i.e 6 + 6 = 12, carry is 1, and digit to store in result is 2
        carry = sum / 10;


    } //end for

    //if there is a remaining carry, add that digit to the result vector
    if (carry > 0)
        result.push_back(carry);
}


void readNumsFillVector(string &num1, string &num2, vector<int> &n1, vector<int> &n2)
{
    cout << "Enter num1: ";
    cin >> num1;

    cout << "Enter num2: ";
    cin >> num2;

    if (num1.length() > 20 || num2.length() > 20)
    {
        cout << "Num1 or num2 exceeds length of 20! Exiting.." << endl;
        exit(-1);
    }

    //Reverse the numbers
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    cout << num1 << endl << num2 << endl;

    //Store num1 digits in a vector
    int i;
    for (i = 0; i < num1.length(); i++)
    {
        if (isdigit(num1[i]))
        {
            n1.push_back(num1[i] - '0'); //offset to get integer
        }
        else
        {
            cout << "Invalid input.." << endl;
            exit(-1);
        }
    }

    //Store num2 digits in a vector
    for (i = 0; i < num2.length(); i++)
    {
        if (isdigit(num2[i]))
        {
            n2.push_back(num2[i] - '0'); //offset to get integer
        }
        else
        {
            cout << "Invalid input.." << endl;
            exit(-1);
        }
    }

}

/*
Sample Run 1
Enter num1: 84516
Enter num2: 3456
61548
6543
Sum = 87972


Sample Run 2
Enter num1: 564
Enter num2: 6649464267
465
7624649466
Sum = 6649464831


Sample Run 3
Enter num1: 5055564055846135535
Enter num2: 1450003558706543211
5355316485504655505
1123456078553000541
Sum = 6505567614552678746

*/
