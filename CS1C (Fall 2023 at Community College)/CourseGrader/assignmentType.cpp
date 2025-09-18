#include "assignmentType.h"
#include "courseType.h"


//Default Constructor
assignmentType::assignmentType()
{
    assignmentName = "EMPTY";
    assignmentDesc = "EMPTY";
    pointsEarned = 0.00;
    pointsPossible = 0.00;
}

//Constructor to take in all data except pointsEarned
assignmentType::assignmentType(string n, string desc, double p)
{
    assignmentName = n;
    assignmentDesc = desc;
    pointsEarned = 0.00; //will change when the assignment is added to the student. student.addStudentHW(assignment goes here, points earned here)
    pointsPossible = p;
}

void assignmentType::setPointsEarned(double d)
{
    pointsEarned = d;
}

string assignmentType::getAssignmentName() const
{
    return assignmentName;
}

double assignmentType::getPointsPossible() const //points for a single assignment
{
    return pointsPossible;
}


double assignmentType::getPointsEarned() const
{
    return pointsEarned;
}

void assignmentType::printAssignment() const
{
    cout << "-----------------------------------------------" << endl;
    cout << "Assignment Title: " << assignmentName << endl;
    cout << "Description: " << assignmentDesc << endl;
    cout << "This assignment is worth: " << pointsPossible << " points" << endl;
    cout << "-----------------------------------------------" << endl << endl;
}
