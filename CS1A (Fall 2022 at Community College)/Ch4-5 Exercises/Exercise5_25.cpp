/*
Ch.5 Programming Exercises Problem 25

Write a complete program to test the code in Example 5-24.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int sum = 0;
    int num = 0;
    int counter;

    ifstream inFile;
    ofstream outFile;

    inFile.open("Exp_5_23.txt");
    outFile.open("Exp_5_23_Output.txt");

    counter = 0;
    inFile >> num;
    while (inFile)
    {
        sum = 0;
        while (num != -999)
        {
            sum = sum + num;
            inFile >> num;
        }
        counter++;
        cout << "Line " << counter << ": Sum = " << sum << endl;
        inFile >> num;
    }

    inFile.close();
    outFile.close();
}
