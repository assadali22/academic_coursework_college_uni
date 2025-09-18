#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

class personType
{
    public:
    //Setters
    void setFirstName(string first);
    void setLastName(string last);
    void setAddress(string newAdd);
    void setHeight(float h);
    void setDOB(string birth);
    void setGender(char gen);

    //Getters
    string getFirstName() const;
    string getLastName() const;
    string getAddress() const;
    float getHeight() const;
    string getDOB() const;
    char getGender() const;

    //Default Constructor
    personType();

    void print() const;
    bool equals(const personType&) const;

    private:
    string firstName;
    string lastName;
    string address;
    double height;
    string dob;
    char gender;
};


#endif
