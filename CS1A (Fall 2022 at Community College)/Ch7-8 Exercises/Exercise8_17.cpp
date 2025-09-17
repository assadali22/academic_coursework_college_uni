/*
Chapter 8 Programming Exercises Problem 17

A company hired 10 temporary workers who are paid hourly and you are
given a data file that contains the last name of the employees, the number
of hours each employee worked in a week, and the hourly pay rate of each
employee. You are asked to write a program that computes each employee’s
weekly pay and the average salary of all the workers. The program
then outputs the weekly pay of each employee, the average weekly pay,
and the names of all the employees whose pay is greater than or equal to
the average pay.
If the number of hours worked in a week is more than 40, then the pay
rate for the hours over 40 is 1.5 times the regular hourly rate.

Use two parallel arrays: a one-dimensional array to store the names of all
the employees, and a two-dimensional array of 10 rows and 3 columns to
store the number of hours an employee worked in a week, the hourly pay
rate, and the weekly pay.

Your program must contain at least the following
functions: a function to read the data from the file into the arrays,
a function to determine the weekly pay, a function to output the names
of all the employees whose pay is greater than or equal to the average
weekly pay, and a function to output each employee's data.

*/


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int EMPLOYEES = 10;
const int EMP_DATA = 3;

//Function Prototype
void readData(string lastName[], double payData[][EMP_DATA], int S);
void findWeeklyPay(double payData[][EMP_DATA], int S);
void showData(const string lastName[], const double payData[][EMP_DATA], int S);

ifstream infile;

int main()
{
    string lastName[EMPLOYEES];
    double payData[EMPLOYEES][EMP_DATA];

    infile.open("Exercise8_17EmpData.txt");

    readData(lastName, payData, EMPLOYEES);
    findWeeklyPay(payData, EMPLOYEES);
    showData(lastName, payData, EMPLOYEES);



    infile.close();
    return 0;

}


void readData(string lastName[], double payData[][EMP_DATA], int S)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < S; i++)
    {
        infile >> lastName[i];
        for (j = 0; j < EMP_DATA - 1; j++) //Index 2 is for calculating weekly pay
        {
            infile >> payData[i][j];
        }
    }

}


void findWeeklyPay(double payData[][EMP_DATA], int S)
{
    int i = 0;
    for (i = 0; i < S; i++)
    {
        if (payData[i][0] > 40)
        {
             payData[i][EMP_DATA - 1] = (40 * payData[i][1]) + ((payData[i][0] - 40) * (1.5 * payData[i][1]));
        }
        else
        {
            payData[i][EMP_DATA - 1] = payData[i][0] * payData[i][1];
        }

    }
}


void showData(const string lastName[], const double payData[][EMP_DATA], int S)
{
    int i = 0;
    double weeklySum = 0;
    double weeklyAvg = 0;
    cout << left;
    cout << fixed << showpoint << setprecision(2);
    cout << setw(15) << "Name" << setw(15) << "Weekly Pay" << endl;
    cout << endl;

    for (i = 0; i < S; i++)
    {
        cout << setw(15) << lastName[i] << setw(15) << payData[i][EMP_DATA - 1] << endl;;
    }
    cout << endl;

    for (i = 0; i < S; i++)
    {
        weeklySum = weeklySum + payData[i][EMP_DATA - 1];
    }
    weeklyAvg = weeklySum / EMPLOYEES;
    cout << "The average weekly pay is $" << weeklyAvg << endl;
    cout << "List of names above average weekly pay: " << endl;

    for (i = 0; i < S; i++)
    {
        if (payData[i][EMP_DATA - 1] > weeklyAvg)
        {
            cout << lastName[i] << endl;
        }
    }
}

/*
Sample Run 1
Name           Weekly Pay

Hendricks      1022.00
Peters         925.00
Mata           840.00
Chan           901.00
Archer         586.50
Rubio          1353.00
Prince         1112.50
Stephens       1196.00
Miranda        1083.00
Kim            1131.00

The average weekly pay is $1015.00
List of names above average weekly pay:
Hendricks
Rubio
Prince
Stephens
Miranda
Kim
*/
