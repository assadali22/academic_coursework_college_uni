/*
(Statistics: compute deviation)
Programming Exercise 5.45 computes the standard deviation of numbers. This exercise uses a different but equivalent formula to compute the
standard deviation of n numbers. Refer Chapter 7 Programming Exercise from the Book on your REVEL Table of Contents.
Scroll to Programming Exercise 7.11 for the formula.
To compute the standard deviation with this formula, you have to store the individual numbers
using an array, so that they can be used after the mean is obtained.

Your program should contain the following methods:
/** Compute the deviation of double values
public static double deviation(double[] x)
/** Compute the mean of an array of double values
public static double mean(double[] x)


Write a test program that prompts the user to enter ten numbers and
displays the mean and standard deviation, as shown in the following sample run:
Sample Run
Enter ten numbers: 1.9 2.5 3.7 2 1 6 3 4 5 2
The mean is 3.11
The standard deviation is 1.55738
*/

import java.util.Scanner;
public class Exercise07_11
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        double num;
        double dataMean;
        double stdDev;
        int i;
        double[] data = new double[10];


        System.out.print("Enter ten numbers: ");
        for (i = 0; i < data.length; i++)
        {
            num = input.nextDouble();
            data[i] = num;
        }

        dataMean = mean(data);
        stdDev = deviation(data);

        System.out.printf("The mean is %.2f\n", dataMean);
        System.out.printf("The standard deviation is %.5f", stdDev);
    }

    public static double deviation(double[] x)
    {
        double d; //return this value for standard deviation
        double numeratorSummation = 0;
        double sum;
        int j;

        //Find the numerator in the standard deviation formula
        for (j = 0; j < x.length; j++)
        {
            numeratorSummation = numeratorSummation + Math.pow(x[j] - mean(x), 2);
        }

        d = Math.sqrt(numeratorSummation / (x.length - 1));
        return d;
    }

    public static double mean(double[] x)
    {
        double m; //return this value for mean
        double sum = 0;
        int j;
        for (j = 0; j < x.length; j++)
        {
            sum = sum + x[j];
        }

        m = sum / (double)(x.length);
        return m;
    }
}
