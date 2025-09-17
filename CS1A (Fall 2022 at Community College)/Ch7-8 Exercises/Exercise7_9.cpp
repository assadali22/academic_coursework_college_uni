/*
Chapter 7 Programming Exercises Problem 9


You are given a file consisting of students' names in the following form:
lastName, firstName middleName. (Note that a student may not have a
middle name.) Write a program that converts each name to the following
form: firstName middleName lastName. Your program must read each
student's entire name in a variable and must consist of a function that takes
as input a string, consists of a student's name, and returns the string consisting
of the altered name. Use the string function find to find the index
of ,; the function length to find the length of the string; and the function
substr to extract the firstName, middleName, and lastName.
*/

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;
    string firstName;
    string lastName;
    string middleName;
    string fullName;
    string restOfName;
    int length = 0;
    int restOfNameLen = 0;
    int commaIndex = 0;
    int spaceIndex = 0;

    infile.open("Exercise7_9_Students.txt");
    outfile.open("Exercise7_9_StudentOutput.txt");

    while(!(infile.eof()))
    {
        getline(infile, fullName);

        length = fullName.length();
        commaIndex = fullName.find(',');
        lastName = fullName.substr(0, commaIndex);
        restOfName = fullName.substr(commaIndex + 2, length);

        spaceIndex = restOfName.find(' ');
        restOfNameLen = restOfName.length();
        if (spaceIndex == ' ')
        {
            firstName = restOfName.substr(0, spaceIndex);
            middleName = restOfName.substr(spaceIndex + 1, restOfNameLen);
        }
        else
        {
            firstName = restOfName;
        }


        outfile << firstName << " ";
        outfile << middleName << lastName << endl;


    }


    cout << "Names successfully processed!" << endl;
    infile.close();
    outfile.close();
    return 0;
}

/*
Input File:
Adams, John
Smith, Sam
Appleseed, Johnny Norman
Rose, Linda
Alfredo, Angel Miller


Output File:
John Adams
Sam Smith
Johnny Norman Appleseed
Linda Rose
Angel Miller Alfredo
*/
