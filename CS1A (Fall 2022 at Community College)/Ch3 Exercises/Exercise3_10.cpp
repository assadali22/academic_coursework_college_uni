/*
Ch.3 Programming Exercises Problem 10

Paula and Danny want to plant evergreen trees along the back side
of their yard. They do not want to have an excessive number of trees.
Write a program that prompts the user to input the following:
a. The length of the yard.
b. The radius of a fully grown tree.
c. The required space between fully grown trees.
The program outputs the number of trees that can be planted in the
yard and the total space that will be occupied by the fully grown trees.
*/

#include <iostream>
using namespace std;

int main()
{
    double yardLength = 0;
    double treeRadius = 0;
    double spaceBetweenTree = 0;

    double totalSpace = 0;
    int numOfTrees = 0;
    double excessLength = 0;

    cout << "Enter yard length: ";
    cin >> yardLength;
    cout << endl;

    cout << "Enter the tree's radius: ";
    cin >> treeRadius;
    cout << endl;

    cout << "Enter space required between each tree: ";
    cin >> spaceBetweenTree;
    cout << endl;


    numOfTrees = yardLength / treeRadius;
    totalSpace = numOfTrees * treeRadius + (spaceBetweenTree * (numOfTrees - 1));
    excessLength = totalSpace - yardLength;


    while (excessLength > treeRadius + spaceBetweenTree || excessLength > 0)
    {
        numOfTrees--;
        totalSpace = totalSpace - (treeRadius + spaceBetweenTree);
        excessLength = excessLength - (treeRadius + spaceBetweenTree);
    }

    cout << "Number of trees that can be planted: " << numOfTrees << endl;
    cout << "Total space occupied: " << totalSpace << endl;
    return 0;
}


/*
Sample Run 1
Enter yard length: 20

Enter the tree's radius: 4

Enter space required between each tree: 2

Number of trees that can be planted: 3
Total space occupied: 16


Sample Run 2
Enter yard length: 100

Enter the tree's radius: 8

Enter space required between each tree: 4

Number of trees that can be planted: 8
Total space occupied: 92


Sample Run 3
Enter yard length: 150

Enter the tree's radius: 12

Enter space required between each tree: 7

Number of trees that can be planted: 8
Total space occupied: 145
*/
