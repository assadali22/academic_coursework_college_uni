/*
Chapter 8 Programming Exercises Problem 13

Write a program to calculate students' average test scores and their
grades. You may assume the following input data:
Johnson 85 83 77 91 76
Aniston 80 90 95 93 48
Cooper 78 81 11 90 73
Gupta 92 83 30 69 87
Blair 23 45 96 38 59
Clark 60 85 45 39 67
Kennedy 77 31 52 74 83
Bronson 93 94 89 77 97
Sunny 79 85 28 93 82
Smith 85 72 49 75 63

Use three arrays: a one-dimensional array to store the students' names,
a (parallel) two-dimensional array to store the test scores, and a parallel
one-dimensional array to store grades. Your program must contain at least
the following functions: a function to read and store data into two arrays,
a function to calculate the average test score and grade, and a function to
output the results. Have your program also output the class average.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
const int SIZE = 10;

//Function Prototype
void readData(string names[], double scores[][5], int S);
void findAvg(double scores[][5], double average[], int S);
void findGrade(double average[], char grades[], int S);
void results(const string names[], const double scores[][5], const double average[], const char grades[], int S);



int main()
{
    string names[SIZE];
    double scores[SIZE][5];
    char grades[SIZE];
    double average[SIZE];

    readData(names, scores, SIZE);
    findAvg(scores, average, SIZE);
    findGrade(average, grades, SIZE);
    results(names, scores, average, grades, SIZE);
    return 0;
}


void readData(string names[], double scores[][5], int S)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < S; i++)
    {
        cout << "Enter student name and 5 scores for student #" << i + 1 << ": ";
        cin >> names[i];
        for (j = 0; j < 5; j++)
        {
            cin >> scores[i][j];
        }
    }
}

void findAvg(double scores[][5], double average[], int S)
{
    int i = 0;
    int k = 0;
    double sum = 0;
    double avg = 0;
    for (i = 0; i < S; i++)
    {
        sum = 0;
        for (k = 0; k < 5; k++)
        {
            sum = sum + scores[i][k];
        }
        avg = sum / static_cast<double>(5);
        average[i] = avg;
    }
}


void findGrade(double average[], char grades[], int S)
{
    int i = 0;
    for (i = 0; i < S; i++)
    {
        if (90 <= average[i] && average[i] <= 100)
        {
            grades[i] = 'A';
        }
        else if (80 <= average[i] && average[i] < 90)
        {
            grades[i] = 'B';
        }
        else if (70 <= average[i] && average[i] < 80)
        {
            grades[i] = 'C';
        }
        else if (60 <= average[i] && average[i] < 70)
        {
            grades[i] = 'D';
        }
        else
        {
            grades[i] = 'F';
        }

    }
}


void results(const string names[], const double scores[][5], const double average[], const char grades[], int S)
{
    int i = 0;
    int k = 0;
    double sumOfAvg = 0;
    double classAvg = 0;
    cout << fixed << showpoint << setprecision(2);
    cout << endl;
    cout << "Results: " << endl;
    for (i = 0; i < S; i++)
    {
        cout << names[i] << " ";
        for (k = 0; k < 5; k++)
        {
            cout << scores[i][k] << " ";
        }
        cout << ", Avg = " << average[i] << ", Grade = " << grades[i] << endl;
    }

    for (i = 0; i < S; i++)
    {
        sumOfAvg = sumOfAvg + average[i];
    }
    classAvg = sumOfAvg / SIZE;
    cout << endl;
    cout << "The class average is: " << classAvg << endl;
}

/*
Sample Run 1
Enter student name and 5 scores for student #1: Johnson 85 83 77 91 76
Enter student name and 5 scores for student #2: Aniston 80 90 95 93 48
Enter student name and 5 scores for student #3: Cooper 78 81 11 90 73
Enter student name and 5 scores for student #4: Gupta 92 83 30 69 87
Enter student name and 5 scores for student #5: Blair 23 45 96 38 59
Enter student name and 5 scores for student #6: Clark 60 85 45 39 67
Enter student name and 5 scores for student #7: Kennedy 77 31 52 74 83
Enter student name and 5 scores for student #8: Bronson 93 94 89 77 97
Enter student name and 5 scores for student #9: Sunny 79 85 28 93 82
Enter student name and 5 scores for student #10: Smith 85 72 49 75 63

Results:
Johnson 85.00 83.00 77.00 91.00 76.00 , Avg = 82.40, Grade = B
Aniston 80.00 90.00 95.00 93.00 48.00 , Avg = 81.20, Grade = B
Cooper 78.00 81.00 11.00 90.00 73.00 , Avg = 66.60, Grade = D
Gupta 92.00 83.00 30.00 69.00 87.00 , Avg = 72.20, Grade = C
Blair 23.00 45.00 96.00 38.00 59.00 , Avg = 52.20, Grade = F
Clark 60.00 85.00 45.00 39.00 67.00 , Avg = 59.20, Grade = F
Kennedy 77.00 31.00 52.00 74.00 83.00 , Avg = 63.40, Grade = D
Bronson 93.00 94.00 89.00 77.00 97.00 , Avg = 90.00, Grade = A
Sunny 79.00 85.00 28.00 93.00 82.00 , Avg = 73.40, Grade = C
Smith 85.00 72.00 49.00 75.00 63.00 , Avg = 68.80, Grade = D

The class average is: 70.94



Sample Run 2
Enter student name and 5 scores for student #1: Messi 89 45 84 68 96
Enter student name and 5 scores for student #2: James 76 81 98 64 92
Enter student name and 5 scores for student #3: John 48 89 87 97 85
Enter student name and 5 scores for student #4: Lisbeth 98 94 85 87 92
Enter student name and 5 scores for student #5: Klein 85 87 72 98 91
Enter student name and 5 scores for student #6: Sam 65 85 87 98 94
Enter student name and 5 scores for student #7: Spongebob 77 75 86 84 81
Enter student name and 5 scores for student #8: Tom 63 68 79 98 90
Enter student name and 5 scores for student #9: Tim 69 68 87 89 85
Enter student name and 5 scores for student #10: Subaru 97 95 67 86 92

Results:
Messi 89.00 45.00 84.00 68.00 96.00 , Avg = 76.40, Grade = C
James 76.00 81.00 98.00 64.00 92.00 , Avg = 82.20, Grade = B
John 48.00 89.00 87.00 97.00 85.00 , Avg = 81.20, Grade = B
Lisbeth 98.00 94.00 85.00 87.00 92.00 , Avg = 91.20, Grade = A
Klein 85.00 87.00 72.00 98.00 91.00 , Avg = 86.60, Grade = B
Sam 65.00 85.00 87.00 98.00 94.00 , Avg = 85.80, Grade = B
Spongebob 77.00 75.00 86.00 84.00 81.00 , Avg = 80.60, Grade = B
Tom 63.00 68.00 79.00 98.00 90.00 , Avg = 79.60, Grade = C
Tim 69.00 68.00 87.00 89.00 85.00 , Avg = 79.60, Grade = C
Subaru 97.00 95.00 67.00 86.00 92.00 , Avg = 87.40, Grade = B

The class average is: 83.06
*/
