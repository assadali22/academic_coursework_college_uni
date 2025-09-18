#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "assignmentType.h"
using namespace std;

class studentType
{
public:
    studentType();
    studentType(string stud, string newID); //student name, id

    void addStudentHW(assignmentType h, double e); //add assignment to the student (totalScore = totalScore + pointsEarned)

    //Setters
    void setName(string n);
    void setID(string newID);
    void setTotalScore(double score);
    void setGrade(char g);

    //Getters
    double getScore() const;
    string getName() const;
    string getID() const;
    char getGrade(double studScore, double maxScore) const;

    //Print
    void print() const;
    void printHWGrades() const;


private:
    string name;
    string studID;
    char grade; //grade in the class
    double totalScore; //total score in the class
    assignmentType studentHW[5];//array of assignments to track unique scores for each student
    int totalAssignmentsForStudent; //variable for array (totalAssignmentsForStudent) NOT STATIC, a student may have more assignments than another student
};


#endif // STUDENTTYPE_H
