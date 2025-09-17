/*
Chapter 8 Programming Exercises Problem 9

Write a program that uses a two-dimensional array to store the highest
and lowest temperatures for each month of the year. The program should
output the average high, average low, and the highest and lowest temperatures
for the year. Your program must consist of the following functions:

a. Function getData: This function reads and stores data in the two
dimensional array.
b. Function averageHigh: This function calculates and returns the
average high temperature for the year.
c. Function averageLow: This function calculates and returns the
average low temperature for the year.
d. Function indexHighTemp: This function returns the index of the
highest high temperature in the array.
e. Function indexLowTemp: This function returns the index of the
lowest low temperature in the array.
*/

#include <iostream>
#include <iomanip>
using namespace std;
const int MONTHS = 12;
//Function Prototype
void getData(int temperatures[][2], int M);
double averageHigh(const int temperatures[][2], int M);
double averageLow(const int temperatures[][2], int M);
int indexHighTemp(const int temperatures[][2], int M);
int indexLowTemp(const int temperatures[][2], int M);


int main()
{
    int temperatures[MONTHS][2]; //High temp is in first column, low temp in second column.
    double highAvg = 0;
    double lowAvg = 0;
    int indexHigh = 0;
    int indexLow = 0;

    getData(temperatures, MONTHS);
    highAvg = averageHigh(temperatures, MONTHS);
    lowAvg = averageLow(temperatures, MONTHS);
    indexHigh = indexHighTemp(temperatures, MONTHS);
    indexLow = indexLowTemp(temperatures, MONTHS);
    cout << fixed << showpoint << setprecision(2);

    cout << "Average high: " << highAvg << endl;
    cout << "Average low: " << lowAvg << endl;
    cout << "Highest temperature: " << temperatures[indexHigh][0] << endl;
    cout << "Lowest temperature: " << temperatures[indexLow][1] << endl;
    return 0;
}


void getData(int temperatures[][2], int M)
{
    int i = 0;
    cout << "Month #1 = January, Month #12 = December" << endl;
    for (i = 0; i < M; i++)
    {
        cout << "Enter high and low temp for month #" << i + 1 << ": ";
        cin >> temperatures[i][0] >> temperatures[i][1];
    }
}


double averageHigh(const int temperatures[][2], int M)
{
    int j = 0;
    double sum = 0;
    double avg = 0;
    for (j = 0; j < M; j++)
    {
        sum = sum + temperatures[j][0];
    }

    avg = static_cast<double>(sum) / static_cast<double>(M);
    return avg;
}


double averageLow(const int temperatures[][2], int M)
{
    int k = 0;
    double sum = 0;
    double avg = 0;
    for (k = 0; k < M; k++)
    {
        sum = sum + temperatures[k][1];
    }

    avg = static_cast<double>(sum) / static_cast<double>(M);
    return avg;
}

int indexHighTemp(const int temperatures[][2], int M)
{
    int i = 0;
    int largeIndex = 0;
    int largeTemp = 0;
    largeTemp = temperatures[i][0];
    for (i = 1; i < M; i++)
    {
        if (temperatures[i][0] > largeTemp)
        {
            largeTemp = temperatures[i][0];
            largeIndex = i;
        }
    }

    return largeIndex;
}


int indexLowTemp(const int temperatures[][2], int M)
{
    int i = 0;
    int lowIndex = 0;
    int lowestTemp = 0;
    lowestTemp = temperatures[i][1];
    for (i = 1; i < M; i++)
    {
        if (temperatures[i][1] < lowestTemp)
        {
            lowestTemp = temperatures[i][1];
            lowIndex = i;
        }
    }

    return lowIndex;
}


/*
Sample Run 1
Month #1 = January, Month #12 = December
Enter high and low temp for month #1: 78 64
Enter high and low temp for month #2: 74 68
Enter high and low temp for month #3: 81 71
Enter high and low temp for month #4: 76 69
Enter high and low temp for month #5: 79 62
Enter high and low temp for month #6: 80 68
Enter high and low temp for month #7: 87 72
Enter high and low temp for month #8: 96 75
Enter high and low temp for month #9: 82 77
Enter high and low temp for month #10: 84 66
Enter high and low temp for month #11: 78 59
Enter high and low temp for month #12: 64 53
Average high: 79.92
Average low: 67.00
Highest temperature: 96
Lowest temperature: 53


Sample Run 2
Month #1 = January, Month #12 = December
Enter high and low temp for month #1: 69 55
Enter high and low temp for month #2: 64 53
Enter high and low temp for month #3: 77 57
Enter high and low temp for month #4: 80 60
Enter high and low temp for month #5: 75 52
Enter high and low temp for month #6: 80 75
Enter high and low temp for month #7: 92 74
Enter high and low temp for month #8: 102 78
Enter high and low temp for month #9: 91 66
Enter high and low temp for month #10: 79 61
Enter high and low temp for month #11: 71 54
Enter high and low temp for month #12: 73 43
Average high: 79.42
Average low: 60.67
Highest temperature: 102
Lowest temperature: 43


Sample Run 3
Month #1 = January, Month #12 = December
Enter high and low temp for month #1: 75 66
Enter high and low temp for month #2: 78 53
Enter high and low temp for month #3: 80 60
Enter high and low temp for month #4: 85 65
Enter high and low temp for month #5: 83 69
Enter high and low temp for month #6: 89 71
Enter high and low temp for month #7: 96 74
Enter high and low temp for month #8: 94 64
Enter high and low temp for month #9: 85 73
Enter high and low temp for month #10: 83 71
Enter high and low temp for month #11: 77 59
Enter high and low temp for month #12: 71 58
Average high: 83.00
Average low: 65.25
Highest temperature: 96
Lowest temperature: 53
*/
