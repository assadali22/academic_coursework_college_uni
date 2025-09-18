#ifndef RECIPEPOSTINSTRUCTION_H
#define RECIPEPOSTINSTRUCTION_H

#include "recipeType.h"

class recipePostInstructionType: public recipeType
{
public:
    void addPostStep(string s);
    void print() const;

private:
    string postStep;
};

#endif // RECIPEPOSTINSTRUCTION_H
