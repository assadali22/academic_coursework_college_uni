#include "studentType.h"
#include "assignmentType.h"


//Default Constructor
studentType::studentType()
{
    name = "EMPTY";
    studID = "EMPTY";
    totalScore = 0.00;
    grade = '0';
    totalAssignmentsForStudent = 0; //track number of assignments for each student
}

//Constructor for name and ID
studentType::studentType(string stud, string newID)
{
    name = stud;
    studID = newID;
    totalScore = 0.00;
    grade = '0'; //initialize to a dummy value
    totalAssignmentsForStudent = 0;
}

//Add homework to a student
void studentType::addStudentHW(assignmentType h, double earned)
{
    studentHW[totalAssignmentsForStudent] = h;
    studentHW[totalAssignmentsForStudent].setPointsEarned(earned); //set points earned for the assignment for a student (i.e 7/10, 7 earned out of 10 possible)
    totalScore = totalScore + earned;
    totalAssignmentsForStudent++;
}

//Setters
void studentType::setName(string n)
{
    name = n;
}

void studentType::setID(string newID)
{
    studID = newID;
}

void studentType::setTotalScore(double score)
{
    totalScore = score;
}

void studentType::setGrade(char g)
{
    grade = g;
}


//Getters
double studentType::getScore() const
{
    return totalScore;
}

string studentType::getName() const
{
    return name;
}

string studentType::getID() const
{
    return studID;
}


char studentType::getGrade(double studScore, double maxScore) const //studScore is the student's score, maxScore is the maxiumum score for the course
{
    char g;
    double percentage;
    percentage = (studScore / maxScore) * 100; //multiply by 100 to get the percentage like 84%, 92%, etc
    //cout << "Percent score for " << name << ": " << percentage << endl; check percentage shows correctly

    if (percentage >= 90.00 && percentage <= 100.00)
    {
        g = 'A';
    }
    else if (percentage >= 80.00 && percentage < 90.00)
    {
        g = 'B';
    }
    else if (percentage >= 70.00 && percentage < 80.00)
    {
        g = 'C';
    }
    else if (percentage >= 60.00 && percentage < 70.00)
    {
        g = 'D';
    }
    else
    {
        g = 'F';
    }
    return g;
}


void studentType::print() const
{
    cout << "-----------------------------------------------" << endl;
    cout << "Student Name: " << name << endl;
    cout << "Student ID: " << studID << endl;
    cout << "Total score in the class: " << totalScore << endl;
    cout << "Grade: " << grade << endl;
    cout << "-----------------------------------------------" << endl << endl;
}


void studentType::printHWGrades() const
{
    cout << "Showing assignment scores for student " << name << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << left;
    cout << setw(20) << "Assignment Name" << setw(20) << "Points Earned" << setw(20) << "Points Possible" << endl;
    int i;
    for (i = 0; i < totalAssignmentsForStudent; i++)
    {
        cout << setw(25) << studentHW[i].getAssignmentName() << setw(20) << studentHW[i].getPointsEarned() << setw(10) << studentHW[i].getPointsPossible() << endl;
    }

    cout << "-------------------------------------------------------------------" << endl;
    cout << "End of student homework list." << endl << endl;
}
