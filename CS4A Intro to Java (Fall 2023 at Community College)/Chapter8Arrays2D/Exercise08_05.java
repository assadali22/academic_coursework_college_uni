import java.util.Scanner;
public class Exercise08_05
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int i;
        int j;
        double num;
        double[][] matrix1 = new double[3][3];
        double[][] matrix2 = new double[3][3];

        System.out.print("Enter matrix1: ");
        for (i = 0; i < matrix1.length; i++)
        {
            for (j = 0; j < matrix1[i].length; j++)
            {
                num = input.nextDouble();
                matrix1[i][j] = num;
            }
        }

        System.out.print("Enter matrix2: ");
        for (i = 0; i < matrix2.length; i++)
        {
            for (j = 0; j < matrix2[i].length; j++)
            {
                num = input.nextDouble();
                matrix2[i][j] = num;
            }
        }

        double[][] newMatrix = addMatrix(matrix1, matrix2);

        printResult(matrix1, matrix2, newMatrix, '+');
    }


    public static void printResult(double[][] m1, double[][] m2, double[][] m3, char op)
    {
        int i;
        int j;
        System.out.println("The addition of the matrices is ");
        System.out.print(" ");
        //Show first row
        for (j = 0; j < m1[0].length; j++)
        {
            System.out.print(m1[0][j] + " ");
        }
        System.out.print("     ");

        for (j = 0; j < m2[0].length; j++)
        {
            System.out.print(m2[0][j] + " ");
        }
        System.out.print("    ");

        for (j = 0; j < m3[0].length; j++)
        {
            System.out.print(" " + m3[0][j]);
        }
        System.out.print("\n");
        System.out.print(" ");


        //Show 2nd row with + and = in the middle adding the matrices for output
        for (j = 0; j < m1[1].length; j++)
        {
            System.out.print(m1[1][j] + " ");
        }
        System.out.print(" " + op + "  ");

        for (j = 0; j < m2[1].length; j++)
        {
            System.out.print(m2[1][j] + " ");
        }
        System.out.print("  =  ");

        for (j = 0; j < m3[1].length; j++)
        {
            System.out.print(m3[1][j] + " ");
        }
        System.out.print("\n");
        System.out.print(" ");


        //Show 3rd row
        for (j = 0; j < m1[2].length; j++)
        {
            System.out.print(m1[2][j] + " ");
        }
        System.out.print("     ");

        for (j = 0; j < m2[2].length; j++)
        {
            System.out.print(m2[2][j] + " ");
        }
        System.out.print("\t");

        for (j = 0; j < m3[2].length; j++)
        {
            System.out.print(m3[2][j] + " ");
        }
    }

    public static double[][] addMatrix(double[][] a, double[][] b)
    {
        double[][] sumMatrices = new double[3][3];
        int i;
        int j;

        for (i = 0; i < sumMatrices.length; i++)
        {
            for (j = 0; j < sumMatrices[i].length; j++)
            {
                sumMatrices[i][j] = a[i][j] + b[i][j];
            }
        }


        return sumMatrices;
    }
}

/*

(Algebra: add two matrices) Write a method to add two matrices. The header of the method is as follows:
public static double[][] addMatrix(double[][] a, double[][] b)
In order to be added, the two matrices must have the same dimensions and the same or compatible types of elements.
Let c be the resulting matrix.

a11 a12 a13   b11 b12 b13   c11 c12 c13
a21 a22 a23 + b21 b22 b23 = c21 c22 c23
a31 a32 a33   b31 b32 b33   c31 c32 c33

Write a test program that prompts the user to enter two 3×3 matrices and displays their sum.

*/
