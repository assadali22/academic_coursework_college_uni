/*
(Area of a convex polygon) https://www.mathwords.com/a/area_convex_polygon.htm
A polygon is convex if it contains any line segment that connects two points of the polygon. Write a program that prompts the user to enter the number of points in a convex polygon, then enter the points clockwise, and display the area of the polygon.
Sample Run
Enter the number of points: 7
Enter the coordinates of the points:
-12 0  -8.5 10   0  11.4 5.5  7.8 6 -5.5 0 -7 -3.5 -5.5

x1  y1  x2  y2  x3   y3   x4  y4


0   1   2   3   4   5    6   7

The total area is 244.575
*/


import java.util.Scanner;
public class Exercise11_15
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int numPoints = 0;
        double convexArea = 0.0;
        System.out.print("Enter the number of points: ");
        numPoints = input.nextInt();

        double[] coordinates = new double[numPoints * 2];
        System.out.print("Enter the coordinates of the points: ");
        for (int i = 0; i < coordinates.length; i++)
        {
            coordinates[i] = input.nextDouble();
        }

        convexArea = findConvexArea(coordinates);
        System.out.println("The total area is " + convexArea);
    }

    public static double findConvexArea(double[] c)
    {
        double area = 0;

        //Multiply and add even index
        double firstSet = 0;
        for (int j = 0, k = 3; j < c.length && k < c.length; j += 2, k +=2)
        {
            firstSet = firstSet + (c[j] * c[k]);
        }

        //Get x(n) * y1
        firstSet = firstSet + (c[1] * c[c.length - 2]);

        //Multiply and add odd index
        double secondSet = 0;
        for (int l = 1, m = 2; l < c.length && m < c.length; l += 2, m += 2)
        {
            secondSet = secondSet + (c[l] * c[m]);
        }

        //Get y(n) * x1
        secondSet = secondSet + (c[0] * c[c.length - 1]);

        area = Math.abs(.5 * (firstSet - secondSet));
        return area;
    }
}

