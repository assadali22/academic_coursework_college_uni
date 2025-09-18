#ifndef RECIPIEBOOK_H
#define RECIPIEBOOK_H

#include "recipeType.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class recipeBookType
{
public:
    //~recipeBookType();
    static int getCount();
    void addRecipe(recipeType recipe);
    void editRecipe(recipeBookType recipeBook, int L);
    int findRecipe(recipeBookType recipeBook, string recipeName);
    void print() const;



private:
    //composition
    recipeType recipes[4];
    static int recipeCount;

};


#endif // RECIPIEBOOK_H
