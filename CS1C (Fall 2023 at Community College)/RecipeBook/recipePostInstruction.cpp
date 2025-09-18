#include "recipePostInstruction.h"
#include "recipeType.h"

void recipePostInstructionType::addPostStep(string s)
{
    postStep = s;

}

void recipePostInstructionType::print() const
{
    recipeType::print();
    cout << "Post instruction: " << postStep << endl;
}
