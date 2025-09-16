//Ch.2 Programming Exercises Problem 5
//Fix the program and put the statements in the correct order.

#include <iostream>
using namespace std;
const double PI = 3.14;

int main()
{
    double radius;
    double circumference;
    double area;

    cout << "Enter the radius: ";
    cin >> radius;
    cout << endl;

    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    cout << "Area = " << area << endl;
    cout << "Circumference = " << circumference << endl;

    return 0;

}


//Test the output
/*
Sample Run 1
Enter the radius: 5

Area = 78.5
Circumference = 31.4


Sample Run 2
Enter the radius: 10

Area = 314
Circumference = 62.8


Sample Run 3
Enter the radius: 8

Area = 200.96
Circumference = 50.24


*/
