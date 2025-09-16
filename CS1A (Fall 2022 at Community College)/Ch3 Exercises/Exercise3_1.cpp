//Ch.3 Programming Exercises Problem 1

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //required for setprecision, fixed, and showpoint
using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;

    string firstName;
    string lastName;
    string department;

    double monthlySalary = 0, bonus = 0, taxes = 0;
    double paycheckWithBonus = 0;
    double paycheck = 0;
    double milesTraveled = 0, timeTraveled = 0, avgSpeed = 0;
    int coffeeSold = 0;
    double coffeeCost = 0, sales = 0;


    infile.open("inData.txt");
    outfile.open("outData.txt");

    cout << "Processing for outData.txt and retrieving data from inData.txt\n" << endl;

    outfile << fixed << showpoint;
    outfile << setprecision(2);


    infile >> firstName >> lastName >> department;
    outfile << "Name: " << firstName << " " << lastName << ", Department: " << department << endl;


    infile >> monthlySalary >> bonus >> taxes;
    outfile << "Monthly Gross Salary: $" << monthlySalary << ", Monthly Bonus: " << bonus << "%, Taxes: " << taxes << "%" << endl;
    paycheckWithBonus = monthlySalary + (monthlySalary * (bonus / 100));
    paycheck = paycheckWithBonus - (paycheckWithBonus * (taxes / 100));
    outfile << "Paycheck: $" << paycheck << "\n" << endl;


    infile >> milesTraveled >> timeTraveled;
    outfile << "Distance Traveled: " << milesTraveled << " miles, Traveling Time: " << timeTraveled << " hours" << endl;
    avgSpeed = milesTraveled / timeTraveled;
    outfile << "Average Speed: " << avgSpeed << " miles per hour\n" << endl;


    infile >> coffeeSold >> coffeeCost;
    outfile << "Number of Coffee Cups Sold: " << coffeeSold << ", Cost: $" << coffeeCost << " per cup" << endl;
    sales = coffeeSold * coffeeCost;
    outfile << "Sales Amount = $" << sales << endl;

    infile.close();
    outfile.close();

    return 0;
}


