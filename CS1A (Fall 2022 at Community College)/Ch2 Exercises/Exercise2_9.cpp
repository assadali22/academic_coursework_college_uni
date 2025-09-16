/*
Ch.2 Programming Exercises Problem 9
Write a program that prompts the user to enter five test scores and then
prints the average test score. (Assume that the test scores are decimal
numbers.)
*/

#include <iostream>
using namespace std;


int main()
{
    double testScore1 = 0;
    double testScore2 = 0;
    double testScore3 = 0;
    double testScore4 = 0;
    double testScore5 = 0;
    double average = 0;

    cout << "Enter 5 test scores: ";
    cin >> testScore1 >> testScore2 >> testScore3 >> testScore4 >> testScore5;
    cout << endl;

    average = (testScore1 + testScore2 + testScore3 + testScore4 + testScore5) / 5;

    cout << "The average of the 5 test scores is: " << average << endl;
    return 0;
}


//Output
/*
Sample Run 1
Enter 5 test scores: 89.5 99.6 94.7 88.2 87.3

The average of the 5 test scores is: 91.86


Sample Run 2
Enter 5 test scores: 88.6 89.1 84.5 83.5 87.0

The average of the 5 test scores is: 86.54


Sample Run 3
Enter 5 test scores: 76.5 87.5 79.9 92.5 85.6

The average of the 5 test scores is: 84.4
*/
