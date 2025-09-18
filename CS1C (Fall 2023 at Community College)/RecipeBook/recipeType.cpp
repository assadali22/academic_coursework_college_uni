#include "recipeType.h"
//Implementation for a single recipe


//Default constructor
recipeType::recipeType()
{
    addIngredient("EMPTY");
    addInstruction("EMPTY");
    addRecipeName("EMPTY");
}
/*
//Destructor
recipeType::~recipeType()
{
    cout << "Default destructor called for single recipe: " << recipeName << endl;
}
*/

string recipeType::getRecipeName()
{
    return recipeName;
}


void recipeType::addIngredient(string s)
{
    ingredient = s;
}


void recipeType::addInstruction(string i)
{
    //for simplicity, short list/sentence of instructions
    step = i;
}


void recipeType::addRecipeName(string n)
{
    recipeName = n;
}



void recipeType::print() const
{
    cout << "Recipe Name: " << recipeName << endl;
    cout << "Ingredients: " << ingredient << endl;
    cout << "Steps: " << step << endl;
}
