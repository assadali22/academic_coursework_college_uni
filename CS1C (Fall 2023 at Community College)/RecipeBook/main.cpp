#include <iostream>
#include "recipeBook.h"
#include "recipeType.h"
#include "recipePostInstruction.h"

using namespace std;

int main()
{
    //there would be one object of recipeBook, recipeBook would have to store the recipe objects itself
    recipeBookType recipeBook;
    cout << "Number of recipes = " << recipeBook.getCount() << endl;

    recipeType pastaRecipe; //Create one recipe object, one recipe without postStep
    pastaRecipe.addRecipeName("Simple Fettuccine Alfredo");
    pastaRecipe.addIngredient("Pasta, Butter, Cream, Seasoning, and Cheese");
    pastaRecipe.addInstruction("Cook the pasta, melt cream and butter together, add cheese sauce to pasta, and enjoy.");
    pastaRecipe.print();


    //Add the recipe to the book
    recipeBook.addRecipe(pastaRecipe);
    cout << "Number of recipes = " << recipeBook.getCount() << endl;
    cout << endl << endl;


    //2nd recipe object with postStep instructions
    recipePostInstructionType chocolateCake;

    chocolateCake.addRecipeName("Chocolate Cake");
    chocolateCake.addIngredient("Vanilla extract, sugar, flour, eggs, butter, baking powder, hot water, and chocolate");
    chocolateCake.addInstruction("Mix butter and chocolate in one bowl. Add vanilla extract, then add eggs. Mix dry ingredients and add vanilla extract.\nAdd hot water, then bake in a pan for 35 minutes at 350 degrees F. Set aside to cool and enjoy!");
    chocolateCake.addPostStep("Add chocolate icing for a creamy rich taste. Combine with ice cream or some M&Ms on the side and enjoy!");
    chocolateCake.print();

    recipeBook.addRecipe(chocolateCake);
    cout << "Number of recipes = " << recipeBook.getCount() << endl;
    cout << endl << endl;



    //3rd recipe object with postStep instructions
    recipePostInstructionType Milkshake;
    Milkshake.addRecipeName("Summer Milkshake");
    Milkshake.addIngredient("Ice cream, milk, toppings (optional)");
    Milkshake.addInstruction("Blend ice cream and milk together in a blender and enjoy.");
    Milkshake.addPostStep("Add sprinkles, whipping cream, and a cherry if desired and enjoy!");
    Milkshake.print();

    recipeBook.addRecipe(Milkshake);
    cout << "Number of recipes = " << recipeBook.getCount() << endl;
    cout << "--------------------------------------------------------------" << endl;


    //Edit recipe
    int loc = 0;
    string editInput;
    cout << "Now editing a recipe" << endl;
    cout << "Enter the name of the recipe to edit: ";
    cin >> editInput;

    loc = recipeBook.findRecipe(recipeBook, editInput);
    if (loc != -1)
    {
        recipeBook.editRecipe(recipeBook, loc);
    }


    //Find recipe
    cin.clear();
    cin.ignore(100, '\n');
    string input;
    cout << "Search for recipe: ";
    cin >> input;

    loc = recipeBook.findRecipe(recipeBook, input);
    if (loc != -1)
    {
        cout << "Recipe location in array: " << loc << endl;
    }
    cout << "--------------------------------------------------------------" << endl;

    //Print the whole recipe book
    cout << "Printing the whole book:" << endl;
    recipeBook.print();

    return 0;
}
