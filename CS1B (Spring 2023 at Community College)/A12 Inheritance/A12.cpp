/*
//-----------------------------------------------------------------------
//Purpose: This program creates two personType objects and three        -
//studentType objects. studentType is the derived class and is publicly -
//inherited from personType (the base class). The program takes in      -
//the data through user input to populate the rest of the data          -
//members for each person and student.                                  -
//-----------------------------------------------------------------------
//Algorithm:                                                            -
//Step 1: Create two personType objects using an array.                 -
//Step 2: Create three studentType objects.                             -
//Step 3: Use a for loop to fill in the data for the two objects of     -
//personType.                                                           -
//Step 4: Use all the setters to fill in all the data for the first     -
//student.                                                              -
//Step 5: Since the 2nd student has the first and last name filled in   -
//by the constructor, use the remaining setters to fill in the rest of  -
//the data members.                                                     -
//Step 6: The 3rd student has the first name, last name, GPA, ID, and   -
classification filled in by the constructor; use the rest of the        -
//setters to populate the remaining data members.                       -
//Step 7: Print the data for all 5 people (objects).                    -
//Step 8: Quit                                                          -
//-----------------------------------------------------------------------

*/


#include "personType.h"
#include "studentType.h"

const int PERSONS = 2;

int main()
{
    int i = 0;
    //Variables for user input
    string first;
    string last;
    string address;
    double height;
    string birthday; //date of birth
    char gen; //gender
    double gpa;
    string id;
    string classification;

    //Instantiate the objects
    personType person[PERSONS]; //Use all setters, default constructor builds the two people
    studentType stud1; //Use all setters
    studentType Jacob("Jacob", "Smith"); //First and Last Name are filled in
    studentType Sam("Sam", "Watson", 4.0, "Freshman", "F124595"); //First Name, Last Name, GPA. Classification, and ID are filled in

    //Get data for objects of personType with for loop
    for (i = 0; i < PERSONS; i++)
    {
        cout << "Enter first name for person #" << i + 1 << ": ";
        cin >> first;
        person[i].setFirstName(first);

        cout << "Enter last name for person #" << i + 1 << ": ";
        cin >> last;
        person[i].setLastName(last);

        cin.ignore(100, '\n');
        cout << "Enter address for person #" << i + 1 << ": ";
        getline(cin, address);
        person[i].setAddress(address);

        cout << "Enter height (in inches) for person #" << i + 1 << ": ";
        cin >> height;
        person[i].setHeight(height);

        cin.ignore(100, '\n');
        cout << "Enter date of birth for person #" << i + 1 << ": ";
        getline(cin, birthday);
        person[i].setDOB(birthday);

        cout << "Enter gender for person #" << i + 1 << ": ";
        cin >> gen;
        person[i].setGender(gen);

        cout << endl << endl;
    }

    //Fill in data for stud1
    cout << "Now entering data for Student 1 (stud1)" << endl;

    cout << "Enter first name for Student 1: ";
    cin >> first;
    stud1.setFirstName(first);

    cout << "Enter last name for Student 1: ";
    cin >> last;
    stud1.setLastName(last);

    cin.ignore(100, '\n');
    cout << "Enter address for Student 1: ";
    getline(cin, address);
    stud1.setAddress(address);

    cout << "Enter height in inches for Student 1: ";
    cin >> height;
    stud1.setHeight(height);

    cin.ignore(100, '\n');
    cout << "Enter date of birth for Student 1: ";
    getline(cin, birthday);
    stud1.setDOB(birthday);

    cout << "Enter gender for Student 1: ";
    cin >> gen;
    stud1.setGender(gen);

    cout << "Enter GPA for Student 1: ";
    cin >> gpa;
    stud1.setGPA(gpa);

    cout << "Enter ID for Student 1: ";
    cin >> id;
    stud1.setID(id);

    cout << "Enter classification for Student 1: ";
    cin >> classification;
    stud1.setClassification(classification);


    //Get Jacob's Data
    cout << endl;
    cout << "Now entering data for " << Jacob.getFirstName() << endl;

    cin.ignore(100, '\n');
    cout << "Enter address for " << Jacob.getFirstName() << ": ";
    getline(cin, address);
    Jacob.setAddress(address);

    cout << "Enter height in inches for " << Jacob.getFirstName() << ": ";
    cin >> height;
    Jacob.setHeight(height);

    cin.ignore(100, '\n');
    cout << "Enter date of birth for " << Jacob.getFirstName() << ": ";
    getline(cin, birthday);
    Jacob.setDOB(birthday);

    cout << "Enter gender for " << Jacob.getFirstName() << ": ";
    cin >> gen;
    Jacob.setGender(gen);

    cout << "Enter GPA for " << Jacob.getFirstName() << ": ";
    cin >> gpa;
    Jacob.setGPA(gpa);

    cout << "Enter ID for " << Jacob.getFirstName() << ": ";
    cin >> id;
    Jacob.setID(id);

    cout << "Enter classification for " << Jacob.getFirstName() << ": ";
    cin >> classification;
    Jacob.setClassification(classification);


    //Get Sam's Data
    cout << endl;
    cout << "Now entering data for " << Sam.getFirstName() << endl;

    cin.ignore(100, '\n');
    cout << "Enter address for " << Sam.getFirstName() << ": ";
    getline(cin, address);
    Sam.setAddress(address);

    cout << "Enter height for " << Sam.getFirstName() << ": ";
    cin >> height;
    Sam.setHeight(height);

    cin.ignore(100, '\n');
    cout << "Enter date of birth for " << Sam.getFirstName() << ": ";
    getline(cin, birthday);
    Sam.setDOB(birthday);

    cout << "Enter gender for " << Sam.getFirstName() << ": ";
    cin >> gen;
    Sam.setGender(gen);

    //Print Data
    cout << fixed << showpoint << setprecision(2);
    person[0].print(); //Base class print method
    person[1].print(); //Base class print method

    stud1.print();
    Jacob.print();
    Sam.print();

    //Compare two students
    cout << "Jacob equivalent to Sam? (Jacob.equals(Sam)) 0 = false, 1 = true: " << Jacob.equals(Sam) << endl;
    return 0;
}

/*
Input Data:

Person 1:
John
Apple
325 Blossom Way
70.5
09/16/1998
M

Person 2:
Angel
Harrison
44 Cherry Ave
62.5
12/12/2004
M


Stud1: (Leslie)
Leslie
Stewart
99 Star Street
64.0
04/12/2001
F
GPA: 4.0
ID: L834911
Classification: Junior



Jacob's Data
56325 San Jose Street
67.0
07/13/2001
M
GPA: 3.5
ID: J832619
Classification: Sophomore

Sam's Data
Address: 845 Orange Ave
Height: 66.5
Birthday: 02/17/1999
Gender: M
*/
