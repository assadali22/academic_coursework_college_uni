/*
Locate the largest element
Write the following method that returns the location of the largest element in a two-dimensional array.
public static int[] locateLargest(double[][] a)


The return value is a one-dimensional array that contains two elements.
These two elements indicate the row and column indices of the largest element in the
two-dimensional array. If there are more than one largest element,
return the smallest row index and then the smallest column index.
Write a test program that prompts the user to enter a two-dimensional array
and displays the location of the largest element in the array.
*/

import java.util.Scanner;
public class Exercise08_13
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int row; //row
        int col; //col
        int i, j;
        double num;

        System.out.print("Enter the number of rows and columns of the array: ");
        row = input.nextInt();
        col = input.nextInt();

        double[][] arr = new double[row][col];

        System.out.println("Enter the array: ");
        for (i = 0; i < arr.length; i++)
        {
            for (j = 0; j < arr[i].length; j++)
            {
                num = input.nextDouble();
                arr[i][j] = num;
            }
        }

        int target[] = locateLargest(arr);

        System.out.print("The location of the largest element is at (" + target[0] + ", " + target[1] + ")");
    }


    public static int[] locateLargest(double[][] a)
    {
        int[] largeArr = new int[2];
        //Assume largest is at index (0,0) in 2D array
        largeArr[0] = 0;
        largeArr[1] = 0;
        double largeNum = a[0][0]; //store largest number in 2D array
        int i;
        int j;

        for (i = 0; i < a.length; i++)
        {
            for (j = 0; j < a[i].length; j++)
            {
                if (largeNum < a[i][j])
                {
                    largeNum = a[i][j];
                    largeArr[0] = i;
                    largeArr[1] = j;

                }
            }
        }

        return largeArr;
    }
}
