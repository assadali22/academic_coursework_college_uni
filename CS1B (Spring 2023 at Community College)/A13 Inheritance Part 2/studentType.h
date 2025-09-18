#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H

#include "personType.h"

class studentType: public personType
{
    public:
        //constructors
        studentType();

        //fName, lName
        studentType(string fName, string lName);

        //fName, lName, GPA, classification, id
        studentType(string fName, string lName, double studGPA, string newClass, string studID);


        //setters
        void setGPA(double newGPA);
        void setID(string newID);
        void setClassification(string newClass);

        //getters
        double getGPA() const;
        string getID() const;
        string getClassification() const;

        //overridden methods
        void print() const; //override the parents' print method
        bool equals(const studentType &) const;

    private:
        string id; //added every id should be unique
        double gpa;
        string classification;
};



#endif
