/*
//-----------------------------------------------------------------------
//Purpose: This program extends A12 by creating a professorType class   -
//that is publicly inherited from personType.                           -
//-----------------------------------------------------------------------
//Algorithm:                                                            -
//Step 1: Create one personType object and pass in all the data using   -
//the constructor.                                                      -
//Step 2: Create two studentType objects, passing in first and last     -
//name, GPA, classification, and student IDs with the constructor.      -
//Step 3: Create two professorType objects and pass in all the data     -
//using the constructor.                                                -
//Step 4: Get the rest of the data through user input for the two       -
students using the appropriate setters.                                 -
//Step 5: Print the data for all 5 people (objects).                    -
//Step 6: Quit                                                          -
//-----------------------------------------------------------------------
*/

#include "personType.h"
#include "studentType.h"
#include "professorType.h"

int main()
{
    personType Alex("Alex", "Thorne", "267 Oakhaven Ave", 64.5, "11/18/1997", 'M');
    studentType Jesse("Jesse", "Klein", 3.75, "Senior", "J87525");
    studentType Steve("Steve", "Jones", 3.60, "Junior", "S96565");
    professorType Bruce("Bruce", "Lee", "55 Haster Road", 72.5, "05/15/1992", 'M', "B-4785721", "Math", "B.S");
    professorType Lily("Lily", "Holland", "74 Dale Street", 68.5, "04/05/1989", 'F', "L-3451278", "Science", "M.S");

    string address;
    double height;
    string birthday;
    char gen;

    //Fill in Jesse's Data
    cout << "Now entering data for " << Jesse.getFirstName() << " (address, height, DOB, gender)" << endl;

    cout << "Enter address for " << Jesse.getFirstName() << ": ";
    getline(cin, address);
    Jesse.setAddress(address);

    cout << "Enter height in inches for " << Jesse.getFirstName() << ": ";
    cin >> height;
    Jesse.setHeight(height);

    cin.ignore(100, '\n');
    cout << "Enter birthday for " << Jesse.getFirstName() << ": ";
    getline(cin, birthday);
    Jesse.setDOB(birthday);

    cout << "Enter gender for " << Jesse.getFirstName() << ": ";
    cin >> gen;
    Jesse.setGender(gen);
    cout << endl;

    //Fill in Steve's Data
    cout << "Now entering data for " << Steve.getFirstName() << " (address, height, DOB, gender)" << endl;

    cin.ignore(100, '\n');
    cout << "Enter address for " << Steve.getFirstName() << ": ";
    getline(cin, address);
    Steve.setAddress(address);

    cout << "Enter height in inches for " << Steve.getFirstName() << ": ";
    cin >> height;
    Steve.setHeight(height);

    cin.ignore(100, '\n');
    cout << "Enter birthday for " << Steve.getFirstName() << ": ";
    getline(cin, birthday);
    Steve.setDOB(birthday);

    cout << "Enter gender for " << Steve.getFirstName() << ": ";
    cin >> gen;
    Steve.setGender(gen);


    //Print Data
    cout << fixed << showpoint << setprecision(2);
    Alex.print();
    Jesse.print();
    Steve.print();
    Bruce.print();
    Lily.print();

    cout << "Jesse equivalent to Steve? (Jesse.equals(Steve)) 1 = true, 0 = false: " << Jesse.equals(Steve) << endl;
    return 0;
}



/*
Input Data
Jesse
Address: 24 Elm Street
Height: 69.0
DOB: 11/12/2001
Gender: M


Steve
Address: 195 Santa Fe Ave
Height: 70.5
DOB: 07/22/2000
Gender: M

*/
