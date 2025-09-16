//Ch.2 Programming Exercises Problem 3

#include <iostream> //3a
using namespace std;


int main()
{
    int num1 = 125;
    int num2 = 28;
    int num3 = -25;
    int average = 0; //3c and 3d from line 9 to 12

    average = (num1 + num2 + num3) / 3; //3e

    cout << "Num1 = " << num1 << " Num2 = " << num2 << " Num3 = " << num3 << endl;
    cout << "The average is " << average << endl;

    return 0;

}

//Output
/*
Num1 = 125 Num2 = 28 Num3 = -25
The average is 42
*/
