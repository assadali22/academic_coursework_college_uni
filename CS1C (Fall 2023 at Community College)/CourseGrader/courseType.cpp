#include "courseType.h"
#include "assignmentType.h"
#include "studentType.h"
double courseType::totalAssignmentPoints = 0.00;
int courseType::numAssignments = 0;
int courseType::numStudents = 0;

//need to add default constructor to student and assignment classes for this to work
courseType::courseType(string t, string id, string n)
{
    instructor = t;
    courseID = id;
    courseName = n;
    maxPointsAllowed = 500.00;
}

double courseType::getMaxPointsAllowed() const
{
    return maxPointsAllowed;
}


void courseType::addStudent(studentType s)
{
    roster[numStudents] = s;
    numStudents++;
}


void courseType::addAssignment(assignmentType a)
{
    if (maxPointsAllowed < (a.getPointsPossible() + totalAssignmentPoints))
    {
        cout << "Unable to add assignment, " << a.getAssignmentName() << " exceeds maximum points allowed for this course, which is " << maxPointsAllowed << " points." << endl;
    }
    else
    {
        hwList[numAssignments] = a;
        numAssignments++;
        totalAssignmentPoints = totalAssignmentPoints + a.getPointsPossible();
    }
}


void courseType::printRoster() const
{
    int i;
    for (i = 0; i < numStudents; i++)
    {
        roster[i].print();
    }
    cout << "End of roster." << endl << endl << endl;
}


void courseType::printAssignments() const
{
    int i;
    for (i = 0; i < numAssignments; i++)
    {
        hwList[i].printAssignment();
    }
    cout << "End of assignment list." << endl << endl << endl;
}


void courseType::printFinalGrade()
{
    char c;
    cout << "-----------------------------------------------" << endl;
    cout << left;
    cout << setw(15) << "Name" << setw(15) << "Student ID" << setw(15) << "Grade" << endl;
    int i;
    for (i = 0; i < numStudents; i++)
    {
        //set the grade for each student so the letter grade is assigned to them
        c = roster[i].getGrade(roster[i].getScore(), maxPointsAllowed);
        roster[i].setGrade(c);
        cout << setw(15) << roster[i].getName() << setw(15) << roster[i].getID() << setw(10) << c << endl;
    }
    cout << "-----------------------------------------------" << endl;
    cout << "End of final grades list." << endl << endl;
}
