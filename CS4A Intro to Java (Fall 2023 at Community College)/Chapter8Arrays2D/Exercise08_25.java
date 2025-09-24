/*
(Markov matrix)
An n by n matrix is called a positive Markov matrix if each element is positive
and the sum of the elements in each column is 1.
Write the following method to check whether a matrix is a Markov matrix.
public static boolean is Markov Matrix(double[][] m)

Write a test program that prompts the user to enter a 3 by 3 matrix of
double values and tests whether it is a Markov matrix. Here are sample runs:


Sample Run 1
Enter a 3-by-3 matrix row by row:
0.15 0.875 0.375
0.55 0.005 0.225
0.30 0.12 0.4
It is a Markov matrix


Sample Run 2
Enter a 3-by-3 matrix row by row:
0.95 -0.875 0.375
0.65 0.005 0.225
0.30 0.22 -0.4
It is not a Markov matrix
*/

import java.util.Scanner;
public class Exercise08_25
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        double[][] matrix = new double[3][3];
        int i;
        int j;
        double numInput;

        System.out.println("Enter a 3-by-3 matrix row by row: ");
        for (i = 0; i < matrix.length; i++)
        {
            for (j = 0; j < matrix[i].length; j++)
            {
                numInput = input.nextDouble();
                matrix[i][j] = numInput;
            }
        }

        if (isMarkovMatrix(matrix))
        {
            System.out.println("It is a Markov matrix");
        }
        else
        {
            System.out.println("It is not a Markov matrix");
        }
    }


    public static boolean isMarkovMatrix(double[][] m)
    {
        int j;
        for (j = 0; j < m.length; j++)
        {
            if ((m[0][j] < 0) || (m[1][j] < 0) || (m[2][j] < 0) || (m[0][j] + m[1][j] + m[2][j] != 1))
            {
                return false;
            }
        }
        return true;
    }


}
