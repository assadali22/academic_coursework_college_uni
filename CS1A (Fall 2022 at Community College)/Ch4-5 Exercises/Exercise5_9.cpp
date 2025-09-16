/*
Ch.5 Programming Exercises Problem 9

Redo Exercise 8 with for loops.

Prompt the user to input two integers: firstNum and secondNum
(firstNum must be less than secondNum).
b. Output all odd numbers between firstNum and secondNum.
c. Output the sum of all even numbers between firstNum and
secondNum.
d. Output the numbers and their squares between 1 and 10.
e. Output the sum of the square of the odd numbers between
firstNum and secondNum.
f. Output all uppercase letters.

*/

#include <iostream>
using namespace std;

const int ONE = 1;
const int TEN = 10;

int main()
{
    int num1 = 0;
    int num2 = 0;
    int start = 0;
    int evenTotal = 0;
    int oddSquareTotal = 0;
    char ch;
    int numToCh = static_cast<int>('A');
    int upperZ = static_cast<int>('Z');

    cout << "Enter num1 and num2: ";
    cin >> num1 >> num2;

    while (num1 > num2)
    {
        cout << "Num1 must be less than num2. Enter num1: ";
        cin >> num1;
    }

    cout << "Odd numbers between num1 and num2: " << endl;
    for (start = num1 + 1; start < num2; start++)
    {
        if (start % 2 != 0)
        {
            cout << start << " ";
        }

    }
    cout << endl;

    cout << "Sum of even numbers in between num1 and num2: ";
    for (start = num1 + 1; start < num2; start++)
    {
        if (start % 2 == 0)
        {
            evenTotal = evenTotal + start;
        }

    }
    cout << evenTotal << endl;


    cout << "Squares of numbers between 1-10: " << endl;
    for (start = ONE; start <= TEN; start++)
    {
        cout << start << "\t\t" << start * start << endl;
    }
    cout << endl;

    cout << "Sum of squares for odd numbers between num1 and num2: ";
    for (start = num1 + 1; start < num2; start++)
    {
        if (start % 2 != 0)
        {
            oddSquareTotal = oddSquareTotal + (start * start);
        }
    }
    cout << oddSquareTotal << endl;

    cout << "Uppercase letters: " << endl;
    for (numToCh; numToCh <= upperZ; numToCh++)
    {
        ch = static_cast<char>(numToCh);
        cout << ch << " ";
    }
    return 0;
}


/*
Sample Run 1
Enter num1 and num2: 11 20
Odd numbers between num1 and num2:
13 15 17 19
Sum of even numbers in between num1 and num2: 60
Squares of numbers between 1-10:
1               1
2               4
3               9
4               16
5               25
6               36
7               49
8               64
9               81
10              100

Sum of squares for odd numbers between num1 and num2: 1044
Uppercase letters:
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z


Sample Run 2
Enter num1 and num2: 14 26
Odd numbers between num1 and num2:
15 17 19 21 23 25
Sum of even numbers in between num1 and num2: 100
Squares of numbers between 1-10:
1               1
2               4
3               9
4               16
5               25
6               36
7               49
8               64
9               81
10              100

Sum of squares for odd numbers between num1 and num2: 2470
Uppercase letters:
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z


Sample Run 3
Enter num1 and num2: 30 45
Odd numbers between num1 and num2:
31 33 35 37 39 41 43
Sum of even numbers in between num1 and num2: 266
Squares of numbers between 1-10:
1               1
2               4
3               9
4               16
5               25
6               36
7               49
8               64
9               81
10              100

Sum of squares for odd numbers between num1 and num2: 9695
Uppercase letters:
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*/
