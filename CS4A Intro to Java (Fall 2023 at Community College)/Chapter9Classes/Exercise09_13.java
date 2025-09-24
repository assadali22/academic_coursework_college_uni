/*
The Location class
Design a class named Location for locating a maximal value and its location in a two-dimensional array.
The class contains public data fields row,column, and maxValue that store the maximal value and its indices in a two-dimensional array with row and column as int types and maxValue as a double type.
Write the following method that returns the location of the largest element in a two-dimensional array:
public static Location locateLargest(double[][] a)
The return value is an instance of Location.

Write a test program that prompts the user to enter a two-dimensional array
and displays the location of the largest element in the array.
If there are more than one largest element, find the location
with the smallest row index and then the smallest column index.


Sample Run
Enter the number of rows and columns in the array:  3 4
Enter the array:
23.5  35  2  10
4.5   3  45  3.5
35   44  5.5  9.6
The largest element is 45, located at (1, 2)
*/

import java.util.Scanner;
public class Exercise09_13
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int r;
        int c;
        System.out.print("Enter the number of rows and columns in the array: ");
        r = input.nextInt();
        c = input.nextInt();

        double[][] arr = new double[r][c];

        System.out.println("Enter the array: ");
        for (int i = 0; i < arr.length; i++)
        {
            for (int j = 0; j < arr[i].length; j++)
            {
                arr[i][j] = input.nextDouble();
            }
        }

        Location large = locateLargest(arr);
        System.out.println("The largest element is " + large.maxValue + " located at (" + large.row + ", " + large.column + ")");

    }
    public static Location locateLargest(double[][] a)
    {
         // Hint for creating a Location object.
         // Assume the max value in a is m and location is at (x, y)
         Location location = new Location();
         location.maxValue = a[0][0];
         location.row = 0;
         location.column = 0;

        for (int i = 0; i < a.length; i++)
        {
            for (int j = 0; j < a[i].length; j++)
            {
                if (a[i][j] > location.maxValue)
                {
                    location.maxValue = a[i][j];
                    location.row = i;
                    location.column = j;
                }
            }
        }

        return location;
    }

}


class Location
{
    public int row = 0;
    public int column = 0;
    public double maxValue = 0.0;
}
