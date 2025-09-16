/*
Chapter 6 Programming Exercises Problem 17

Consider the following C++ code. The function func2 has three
parameters of type int, int, and double, say a, b, and c,
respectively. Write the definition of func2 so that its action is
as follows:
a. Prompt the user to input two integers and store the numbers in a
and b, respectively.
b. If both of the numbers are nonzero:
If a >= b, the value assigned to c is a to the power b, that is a^b.
If a < b, the value assigned to c is b to the power a, that is, b^a.

c. If a is nonzero and b is zero, the value assigned to c is the
square root of the absolute value of a.
d. If b is nonzero and a is zero, the value assigned to c is the
square root of the absolute value of b.
e. Otherwise, the value assigned to c is 0.
*/


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void func1();
void func2(int& a, int& b, double& c);


int main()
{
    int num1, num2;
    double num3;
    int choice;
    cout << fixed << showpoint << setprecision(2);

    do
    {
        func1();
        cin >> choice;
        cout << endl;
        if (choice == 1)
        {
            func2(num1, num2, num3);
            cout << num1 << ", " << num2 << ", " << num3 << endl;
        }
    }
    while (choice != 99);

    return 0;
}


void func1()
{
    cout << "To run the program, enter 1." << endl;
    cout << "To exit the pogram, enter 99." << endl;
    cout << "Enter 1 or 99: ";
}


void func2(int& a, int& b, double& c)
{
    cout << "Enter num1 and num2: ";
    cin >> a >> b;

    if (a > 0 && b > 0)
    {
        if (a >= b)
        {
            c = pow(a, b);
        }
        else if (a < b)
        {
            c = pow(b, a);
        }
    }

    else if (a > 0 && b == 0)
    {
        c = sqrt(fabs(a));
    }
    else if (b > 0 && a == 0)
    {
        c = sqrt(fabs(b));
    }
    else
    {
        c = 0;
    }

}

/*
Sample Run 1
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 1

Enter num1 and num2: 4 8
4, 8, 4096.00
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 1

Enter num1 and num2: 9 5
9, 5, 59049.00
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 1

Enter num1 and num2: 0 16
0, 16, 4.00
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 1

Enter num1 and num2: 25 0
25, 0, 5.00
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 1

Enter num1 and num2: 0 0
0, 0, 0.00
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 99


Sample Run 2
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 1

Enter num1 and num2: -4 2
-4, 2, 0.00
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 1

Enter num1 and num2: 2 -4
2, -4, 0.00
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 1

Enter num1 and num2: 0 -16
0, -16, 0.00
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 99


Sample Run 3
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 1

Enter num1 and num2: 12 0
12, 0, 3.46
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 1

Enter num1 and num2: 0 38
0, 38, 6.16
To run the program, enter 1.
To exit the pogram, enter 99.
Enter 1 or 99: 99

*/
