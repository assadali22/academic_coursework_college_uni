/*
Ch.5 Programming Exercises Problem 19

Enhance the program that you wrote in Exercise 18 by modifying it as
follows: When the students started selling cookies, they were told that
the students who sell the maximum number of boxes will have 10% of
the money they generate donated to their favorite charitable organization.
So, in addition to the output your program generated in Exercise 18,
your program should output the names of all the students selling the
maximum number of boxes and the amount that will be donated to their
favorite charitable organization.

18. The program in Example 5-4 uses a sentinel control loop to process
cookies sales data. Assume that the data is provided in a file and the
first line in the file specifies the cost of one box. Modify the program
so that it uses an EOF-controlled loop to process the data.


*/

//Lets say that the maximum boxes they need to sell is 300.
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    string name;
    int numOfVolunteers = 0;
    int numOfBoxesSold;
    int maxBoxes = 300;
    int totalNumOfBoxesSold = 0;
    double costOfOneBox;
    double donation = 0;
    int volunteersSoldMax = 0;
    int i;

    ifstream fin;
    ofstream fout;

    fin.open("Ch5_Ex19_Data.txt");
    fout.open("Ch5_Ex19_Output.txt");

    fout << fixed << showpoint << setprecision(2);
    fin >> costOfOneBox;
    cout << "Processing cookie sales data and amount for charity, check Ch5_Ex19_Output.txt." << endl;

    fin >> name;

    while (!(fin.eof()))
    {
        fin >> numOfBoxesSold;
        if (numOfBoxesSold >= maxBoxes)
        {
            fout << name << " sold the maximum amount of boxes." << endl;
            volunteersSoldMax++;
        }
        totalNumOfBoxesSold = totalNumOfBoxesSold + numOfBoxesSold;
        numOfVolunteers++;
        fin >> name;
    }
    fout << endl;

    fout << "The total number of boxes sold: " << totalNumOfBoxesSold << endl;

    fout << "The total money made by selling cookies: $"
    << totalNumOfBoxesSold * costOfOneBox << endl;

    if (numOfVolunteers != 0)
    {
        fout << "The average number of boxes sold by each volunteer: "
        << totalNumOfBoxesSold / numOfVolunteers << endl;

        for (i = 0; i < volunteersSoldMax; i++)
        {
            donation = donation + (totalNumOfBoxesSold * costOfOneBox * .10);
        }

        fout << "Amount going to charity: $" << donation << endl;
    }

    else
    {
        fout << "No input." << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
