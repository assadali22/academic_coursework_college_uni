/*
Ch.5 Programming Exercises Problem 15

The program in Example 5-6 implements the Number Guessing Game.
However, in that program, the user is given as many tries as needed to
guess the correct number. Rewrite the program so that the user has no
more than five tries to guess the correct number. Your program should
print an appropriate message, such as "You win!" or "You lose!".

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    int num;
    int guess;
    int tries = 1;
    bool isGuessed = false;

    srand(time(0));
    num = rand() % 100;

    while (tries <= 5 && !(isGuessed))
    {
        cout << "Enter an integer greater than or equal to 0 and less than 100: ";
        cin >> guess;
        cout << endl;

        if (guess == num)
        {
            cout << "You guessed the correct number." << endl;
            cout << "You took " << tries << " tries";
            isGuessed = true;
        }

        else if (guess < num)
        {
            cout << "Your guess is lower than the number.\n Guess again!" << endl;
            tries++;
        }

        else
        {
            cout << "Your guess is higher than the number.\n Guess again!" << endl;
            tries++;
        }
    }
    return 0;
}
