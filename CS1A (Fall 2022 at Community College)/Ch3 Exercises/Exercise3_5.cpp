/*
Ch.3 Programming Exercises Problem 5
Three employees in a company are up for a special pay increase. You
are given a file, say Ch3_Ex5Data.txt, with the following data:
Miller Andrew 65789.87 5
Green Sheila 75892.56 6
Sethi Amit 74900.50 6.1

Each input line consists of an employee’s last name, first name, current
salary, and percent pay increase. For example, in the first input line,
the last name of the employee is Miller, the first name is Andrew,
the current salary is 65789.87, and the pay increase is 5%.

Write a program that reads data from the specified file and stores the
output in the file Ch3_Ex5Output.dat. For each employee, the data
must be output in the following form: firstName lastName updatedSalary.
Format the output of decimal numbers to two decimal places.

*/


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;

    string firstName;
    string lastName;

    int i = 0;
    double currentSalary = 0;
    double payIncrease = 0;
    double updatedSalary = 0;

    cout << "Processing for Ch3_Ex5Output.dat and retrieving data from Ch3_Ex5Data.txt\n" << endl;

    infile.open("Ch3_Ex5Data.txt");
    outfile.open("Ch3_Ex5Output.dat");

    for (i = 0; i <= 2; i++)
    {
        outfile << fixed << showpoint;
        outfile << setprecision(2);

        infile >> lastName >> firstName;
        outfile << firstName << " " << lastName << " ";
        infile >> currentSalary >> payIncrease;

        updatedSalary = currentSalary + (currentSalary * (payIncrease / 100));
        outfile << updatedSalary << endl;

    }

    infile.close();
    outfile.close();

    return 0;
}
