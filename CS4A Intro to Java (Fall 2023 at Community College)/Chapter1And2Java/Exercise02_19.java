/*
Write a program that prompts the user to enter three points
(x1, y1), (x2, y2), (x3, y3) of a triangle and displays its area.
The formula for computing the area of a triangle is:
s = (side1 + side2 + side3) / 2;
area = sqrt( s(s - side1)(s - side2)(s - side3))


Sample Run
Enter three points for a triangle:
1.5  -3.4
4.6  5
9.5  -3.4
The area of the triangle is 33.6
*/

//FIRST TRY!
import java.util.Scanner;

public class Exercise02_19
{
    public static void main(String[] args)
    {
        //Variables
        double x1, x2, x3;
        double y1, y2, y3;
        double s;
        double s1Expression, s2Expression, s3Expression; //value under the square root when finding distance
        double side1, side2, side3;
        double area;
        Scanner input = new Scanner(System.in);

        //Input
        System.out.println("Enter three points for a triangle: ");
        x1 = input.nextDouble();
        y1 = input.nextDouble();

        x2 = input.nextDouble();
        y2 = input.nextDouble();

        x3 = input.nextDouble();
        y3 = input.nextDouble();

        //Calculation
        //Distance/length between (x1, y1) and (x2, y2)
        s1Expression = Math.pow(x2 - x1 , 2) + Math.pow(y2 - y1 , 2);
        side1 = Math.pow(s1Expression, 0.5);
        
        //Distance/length between (x2, y2) and (x3, y3)
        s2Expression = Math.pow(x3 - x2 , 2) + Math.pow(y3 - y2 , 2);
        side2 = Math.pow(s2Expression, 0.5);
        
        //Distance/length between (x3, y3) and (x1, y1)
        s3Expression = Math.pow(x1 - x3 , 2) + Math.pow(y1 - y3 , 2);
        side3 = Math.pow(s3Expression, 0.5);
        
        s = (side1 + side2 + side3) / 2;
        area = Math.pow(s *(s - side1) * (s - side2) * (s - side3), 0.5);
        
        //Output
        System.out.println("The area of the triangle is " + area);
    }
}