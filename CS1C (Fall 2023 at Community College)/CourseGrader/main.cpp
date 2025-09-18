#include <iostream>
#include <iomanip>
#include "courseType.h"
#include "assignmentType.h"
#include "studentType.h"

using namespace std;

int main()
{
    //Declare objects
    studentType Chris("Chris", "CH1775");
    studentType Amy("Amy", "AY2707");
    assignmentType Ch10("Chapter 10", "Complete 3 Chapter 10 Exercises", 100);
    assignmentType Ch11("Chapter 11", "Complete 1 Chapter 11 Exercise", 200);
    assignmentType Exam1("Exam 1", "Create a simple fast food menu with classes.", 200);
    courseType computerScience("Homi", "CS1C", "Intro to Computer Science III");
    char grade;


    //Add assignments
    cout << "Adding assignments to the course and to each student. Assign grades before adding student to the class roster." << endl;
    computerScience.addAssignment(Ch10);
    computerScience.addAssignment(Ch11);
    computerScience.addAssignment(Exam1);


    //Add assignment scores to students first
    Amy.addStudentHW(Ch10, 80.00);
    Amy.addStudentHW(Ch11, 155.5);
    Amy.addStudentHW(Exam1, 172.5);

    Chris.addStudentHW(Ch10, 90.00);
    Chris.addStudentHW(Ch11, 165.5);
    Chris.addStudentHW(Exam1, 110.00);


    //Get the grade for the student and set it
    grade = Amy.getGrade(Amy.getScore(), computerScience.getMaxPointsAllowed());
    Amy.setGrade(grade);

    grade = Chris.getGrade(Chris.getScore(), computerScience.getMaxPointsAllowed());
    Chris.setGrade(grade);
    cout << "Grades have been assigned." << endl;


    //Add students (this goes LAST, not first, roster[i].print() (print function in studentType) wont't work right because their scores would be 0 when assigned into the roster.)
    //Grades also need to be added first before going into the roster, otherwise the roster will have 0 as the grade if students are added first without their grade
    //studentType object by itself and a studentType object in an array through aggregation are completely different (independent) objects. Changing one of their data members to a different value won't affect the other object.
    cout << "Adding student Chris" << endl;
    computerScience.addStudent(Chris);
    cout << "Adding student Amy" << endl;
    computerScience.addStudent(Amy);


    //Print data
    cout << "After adding students, call the student print method." << endl;
    Chris.print();
    Amy.print();

    cout << "Printing final grade: " << endl;
    computerScience.printFinalGrade();


    cout << "After printing final grade, the roster is: " << endl;
    computerScience.printRoster();


    //Print assignments from course class
    cout << "Printing assignment from the course class: " << endl;
    computerScience.printAssignments();


    //Try to add another assignment that will exceed maximum points for the coursee
    cout << "Attempting to add Chapter 12 assignment..." << endl;
    assignmentType Ch12("Chapter 12", "Complete 2 Chapter 12 Pointer Exercises.", 50); //attempt to add this one, wont add due to max points for the course
    computerScience.addAssignment(Ch12);

    cout << "Assignment list after trying to add Chapter 12: " << endl;
    computerScience.printAssignments();


    //Print homework scores for each student
    cout << "Printing assignment data for each student." << endl;
    Chris.printHWGrades();
    Amy.printHWGrades();

    //cout << &Amy.studentHW[0] << endl;
    //cout << &Chris.studentHW[0] << endl;
    return 0;
}
