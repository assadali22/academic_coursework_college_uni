/*
A linear equation can be solved using Cramer’s rule given in Programming Exercise 1.13.
Write a program that prompts the user to enter a, b, c, d, e, and f and displays the result.
If ad - bc is 0, report The equation has no solution.

Sample Run 1
Enter a, b, c, d, e, f: 9.0  4.0  3.0  -5.0  -6.0  -21.0
x is -2.0 and y is 3.0


Sample Run 2
Enter a, b, c, d, e, f: 1.0  2.0  2.0  4.0  4.0  5.0
The equation has no solution


Sample Run 3
Enter a, b, c, d, e, f: 1.0  2.0  2.0  4.0  4.0  5.0 6.0
x is -4.0 and y is 4.5


Cramer's rule is given by:
ax + by = e
cx + dy = f

x = (ed - bf) / (ad - bc)

y = (af - ec) / (ad - bc)
*/

import java.util.Scanner;

public class Exercise03_03
{
    public static void main(String[] args)
    {
        //Variables
        double a, b, c;
        double d, e, f;
        double x, y;
        Scanner input = new Scanner(System.in);

        //Input
        System.out.println("Enter a, b, c, d, e, f: ");
        a = input.nextDouble();
        b = input.nextDouble();
        c = input.nextDouble();
        d = input.nextDouble();
        e = input.nextDouble();
        f = input.nextDouble();

        //Calculation and Output
        if ((a * d - b * c) != 0)
        {
            x = (e * d - b * f) / (a * d - b * c);
            y = (a * f - e * c) / (a * d - b * c);

            System.out.println("x is " + x + " and y is " + y);
        }
        else
        {
            System.out.println("The equation has no solution");
        }
    }
}
