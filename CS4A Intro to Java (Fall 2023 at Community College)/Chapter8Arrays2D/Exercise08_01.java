/*
(Sum elements column by column)
Write a method that returns the sum of all the elements in a specified column in a matrix using the following header:
public static double sumColumn(double[][] m, int columnIndex)
Write a test program that reads a 3-by-4 matrix and displays the sum of each column.


Sample Run
Enter a 3-by-4 matrix row by row:
1.5 2 3 4
5.5 6 7 8
9.5 1 3 1
Sum of the elements at column 0 is 16.5
Sum of the elements at column 1 is 9.0
Sum of the elements at column 2 is 13.0
Sum of the elements at column 3 is 13.0
*/

import java.util.Scanner;
public class Exercise08_01
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        double[][] matrix = new double[3][4];
        int i;
        int j;
        double number;


        //Fill array with user input
        System.out.print("Enter a 3-by-4 matrix row by row: ");
        for (i = 0; i < matrix.length; i++)
        {
            for (j = 0; j < matrix[i].length; j++)
            {
                number = input.nextDouble();
                matrix[i][j] = number;
            }
        }

        i = 0;
        j = 0;
        //Sum each column
        for (j = 0; j < matrix[i].length; j++)
        {
            System.out.println("Sum of the elements at column " + j + " is " + sumColumn(matrix, j));
        }

    }

    public static double sumColumn(double[][] m, int columnIndex)
    {
        double sum = 0;
        int i = 0;


        for (i = 0; i < m.length; i++)
        {
            sum += m[i][columnIndex];
        }

        return sum;
    }
}
