#ifndef RECIPETYPE_H
#define RECIPETYPE_H
//Store recipes in recipe book
#include <iostream>
#include <string>
using namespace std;

class recipeType
{
public:
    recipeType();
    //~recipeType();
    string getRecipeName();
    void addIngredient(string s);
    void addInstruction(string i);
    void addRecipeName(string n);
    void print() const;

private:
    string ingredient; //user would type in a short list of ingredients
    string step; //type a short list of steps
    string recipeName;
};
#endif // RECIPETYPE_H
