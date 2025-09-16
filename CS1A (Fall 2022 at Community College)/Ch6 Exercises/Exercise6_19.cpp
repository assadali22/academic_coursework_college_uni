/*
Chapter 6 Programming Exercises Problem 19

The function printGrade in Example 6-13 is written as a void function
to compute and output the course grade. The course score is
passed as a parameter to the function printGrade. Rewrite the function
printGrade as a value-returning function so that it computes and
returns the course grade. (The course grade must be output in the function
main.) Also, change the name of the function to calculateGrade.
*/

#include <iostream>
using namespace std;

char calculateGrade(int cScore);

int main()
{
    char grade;
    int cScore;

    cout << "Enter score: ";
    cin >> cScore;

    grade = calculateGrade(cScore);

    cout << "Score = " << cScore << ", grade = " << grade << endl;

    return 0;
}



char calculateGrade(int cScore)
{
    if (cScore >= 90)
    {
        return 'A';
    }
    else if (cScore >= 80)
    {
        return 'B';
    }
    else if(cScore >= 70)
    {
        return 'C';
    }
    else if (cScore >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

/*
Sample Run 1
Enter score: 88
Score = 88, grade = B

Sample Run 2
Enter score: 72
Score = 72, grade = C

Sample Run 3
Enter score: 68
Score = 68, grade = D
*/
