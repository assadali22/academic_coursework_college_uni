#include "recipeBook.h"
#include "recipeType.h"

int recipeBookType::recipeCount = 0;

//Implementation for a recipe book

//there should be a default constructor by default

/*
//Destructor
recipeBookType::~recipeBookType()
{
    cout << "Default destructor called for the recipeBook" << endl;
    recipeCount--;
}
*/

int recipeBookType::getCount()
{
    return recipeCount;
}

void recipeBookType::addRecipe(recipeType recipe)
{
    recipes[recipeCount] = recipe;
    recipeCount++;
}


void recipeBookType::editRecipe(recipeBookType recipeBook, int L)
{

    char ch;
    string edit;
    cout << "Choose what to edit about the recipe (1 = recipe name, 2 = ingredients, 3 = steps): ";
    cin >> ch;
    cin.ignore(100, '\n'); //clear the \n before doing a getline

    switch (ch)
    {
        case '1':
        {
            cout << "Enter new recipe name: ";
            getline(cin, edit);
            recipes[L].addRecipeName(edit);
            break;
        }

        case '2':
        {
            cout << "Enter new ingredients or modify ingredient list: ";
            getline(cin, edit);
            recipes[L].addIngredient(edit);
            break;
        }

        case '3':
        {
            cout << "Enter new steps/modify recipe instructions: ";
            getline(cin, edit);
            recipes[L].addInstruction(edit);
            break;
        }
        default:
        {
            cout << "Invalid choice, try again." << endl;
        }
    }

}


int recipeBookType::findRecipe(recipeBookType recipeBook, string recipeName)
{
    int i = 0;
    int j = 0;
    char choice;
    string temp;
    int length = 0;

    //Lowercase the recipe name that was passed in
    length = recipeName.length();
    for (i = 0; i < length; i++)
    {
        recipeName[i] = tolower(recipeName[i]);
    }

    //Find the recipe
    for (i = 0; i < recipeCount; i++)
    {
        //lowercase the recipe in the book
        temp.append(recipes[i].getRecipeName());
        length = temp.length();
        for (j = 0; j < length; j++)
        {
            temp[j] = tolower(temp[j]);
        }


        if (temp.find(recipeName) != string::npos)
        {
            cout << "Match Found:" << endl;
            recipes[i].print();
            cout << "Is this the recipe you want? (Y/N): ";
            cin >> choice;

            if (choice == 'Y' || choice == 'y')
            {
                cout << "The recipe is in the recipe book." << endl;
                cout << "Recipe name: " << recipes[i].getRecipeName() << endl;
                return i;
            }
            cout << endl;
        }
        temp.erase();
    }

    cout << "Recipe not found." << endl;
    return -1;

}

void recipeBookType::print() const
{
    int i;
    for (i = 0; i < recipeCount; i++)
    {
        recipes[i].print();

        cout << endl << endl;
        cout << "--------------------------------------------------------------" << endl;
    }
}
