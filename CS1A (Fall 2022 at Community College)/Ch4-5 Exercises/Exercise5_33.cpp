/*
Ch.5 Programming Exercises Problem 33

Bianca is preparing special dishes for her daughter’s birthday. It takes
her a minutes to prepare the first dish, and each following dish takes
b minutes longer than the previous dish. She has t minutes to prepare
the dishes. For example, if the first dish takes a = 10 minutes and
b = 5, then the second dish will take 15 minutes, the third dish will take
20 minutes, and so on. If she has 80 minutes to prepare the dishes,
then she can prepare four dishes because 10 + 15 + 20 + 25 = 70.
Write a program that prompts the user to enter the values of a, b, and
t, and outputs the number of dishes Bianca can prepare.
*/

#include <iostream>
using namespace std;

int main()
{
    int numOfDishes = 0;
    int totalTime = 0;
    int nextNum;
    int a = 0;
    int b = 0;
    int t = 0;

    cout << "Enter amount of time, in minutes, to prepare the first dish: ";
    cin >> a;

    cout << "Enter how much longer each following dish takes than the previous dish: ";
    cin >> b;

    cout << "Enter total amount of time to prepare all dishes: ";
    cin >> t;

    for (nextNum = a; totalTime < t; nextNum = nextNum + b)
    {
        totalTime = totalTime + nextNum;
        if (totalTime <= t)
        {
          numOfDishes++;
        }

    }

    cout << "Number of dishes that can be prepared: " << numOfDishes << endl;
    return 0;
}

/*
Sample Run 1
Enter amount of time, in minutes, to prepare the first dish: 10
Enter how much longer each following dish takes than the previous dish: 5
Enter total amount of time to prepare all dishes: 80
Number of dishes that can be prepared: 4

Sample Run 2
Enter amount of time, in minutes, to prepare the first dish: 15
Enter how much longer each following dish takes than the previous dish: 10
Enter total amount of time to prepare all dishes: 90
Number of dishes that can be prepared: 3

Sample Run 3
Enter amount of time, in minutes, to prepare the first dish: 5
Enter how much longer each following dish takes than the previous dish: 10
Enter total amount of time to prepare all dishes: 180
Number of dishes that can be prepared: 6
*/
