#ifndef ASSIGNMENTTYPE_H
#define ASSIGNMENTTYPE_H

#include <iostream>
#include <string>
using namespace std;

class assignmentType
{
public:
    assignmentType();
    assignmentType(string n, string desc, double p);
    void setPointsEarned(double d);


    string getAssignmentName() const;
    double getPointsPossible() const; //points for a single assignment
    double getPointsEarned() const; //points a student earns
    void printAssignment() const;

private:
    string assignmentName;
    string assignmentDesc;
    double pointsEarned; //points the student earns i.e 7 out of 10
    double pointsPossible;
};


#endif // ASSIGNMENTTYPE_H
