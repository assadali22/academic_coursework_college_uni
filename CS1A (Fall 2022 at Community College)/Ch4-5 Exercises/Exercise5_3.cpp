/*
Ch.5 Programming Exercises Problem 3

The program Telephone Digits outputs only telephone digits that
correspond to uppercase letters. Rewrite the program so that it processes
both uppercase and lowercase letters and outputs the corresponding
telephone digit. If the input is something other than an uppercase or
lowercase letter, the program must output an appropriate error message.
*/

#include <iostream>
using namespace std;

int main()
{

    char letter;
    int digit = 0;
    int num = 0;

    cout << "Enter a letter, # to quit: ";
    cin >> letter;

    while (letter != '#')
    {
        cout << "Letter: " << letter << endl;
        cout << "Corresponding telephone digit: ";

        if (letter >= 'A' && letter <= 'Z')
        {
            num = static_cast<int>(letter) - static_cast<int>('A');
            if (0 <= num && num < 26)
            {
                digit = (num / 3) + 2;
                if (((num / 3 == 6 ) || (num / 3 == 7)) && (num % 3 == 0))
                {
                    digit = digit - 1;
                }

                if (digit > 9)
                {
                    digit = 9;
                }

                cout << digit << endl;
            }
        }

        else if (letter >= 'a' && letter <= 'z')
        {
            num = static_cast<int>(letter) - static_cast<int>('a');
            if (0 <= num && num < 26)
            {
                digit = (num / 3) + 2;
                if (((num / 3 == 6 ) || (num / 3 == 7)) && (num % 3 == 0))
                {
                    digit = digit - 1;
                }

                if (digit > 9)
                {
                    digit = 9;
                }

                cout << digit << endl;
            }

        }

        else
        {
            cout << "Invalid input." << endl;
        }

        cout << "Enter a letter, # to quit: ";
        cin >> letter;
    }
    return 0;
}


/*
Sample Run 1
Enter a letter, # to quit: a
Letter: a
Corresponding telephone digit: 2
Enter a letter, # to quit: A
Letter: A
Corresponding telephone digit: 2
Enter a letter, # to quit: e
Letter: e
Corresponding telephone digit: 3
Enter a letter, # to quit: E
Letter: E
Corresponding telephone digit: 3
Enter a letter, # to quit: h
Letter: h
Corresponding telephone digit: 4
Enter a letter, # to quit: H
Letter: H
Corresponding telephone digit: 4
Enter a letter, # to quit: #


Sample Run 2
Enter a letter, # to quit: j
Letter: j
Corresponding telephone digit: 5
Enter a letter, # to quit: J
Letter: J
Corresponding telephone digit: 5
Enter a letter, # to quit: n
Letter: n
Corresponding telephone digit: 6
Enter a letter, # to quit: N
Letter: N
Corresponding telephone digit: 6
Enter a letter, # to quit: p
Letter: p
Corresponding telephone digit: 7
Enter a letter, # to quit: P
Letter: P
Corresponding telephone digit: 7
Enter a letter, # to quit: #


Sample Run 3
Enter a letter, # to quit: t
Letter: t
Corresponding telephone digit: 8
Enter a letter, # to quit: T
Letter: T
Corresponding telephone digit: 8
Enter a letter, # to quit: w
Letter: w
Corresponding telephone digit: 9
Enter a letter, # to quit: W
Letter: W
Corresponding telephone digit: 9
Enter a letter, # to quit: y
Letter: y
Corresponding telephone digit: 9
Enter a letter, # to quit: Y
Letter: Y
Corresponding telephone digit: 9
Enter a letter, # to quit: #
*/
