#ifndef COURSETYPE_H
#define COURSETYPE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "assignmentType.h"
#include "studentType.h"
using namespace std;

class courseType
{
public:
    courseType(string t, string id, string n);
    double getMaxPointsAllowed() const;
    void addStudent(studentType s); //add a student to the course
    void addAssignment(assignmentType a); //add a homework assignment to the course

    //Print
    void printRoster() const;
    void printAssignments() const;
    void printFinalGrade();


private:
    //course details
    string instructor;
    string courseID; //CS1C for example
    string courseName;
    double maxPointsAllowed; //maximum score in the course (ex. 1000 points)

    //Aggregation arrays
    studentType roster[5];
    assignmentType hwList[5];

    //Static variables to keep track of array and to check for total assignmentPoints
    static double totalAssignmentPoints;
    static int numAssignments; //count the number of assignments
    static int numStudents;

};


#endif // COURSETYPE_H
