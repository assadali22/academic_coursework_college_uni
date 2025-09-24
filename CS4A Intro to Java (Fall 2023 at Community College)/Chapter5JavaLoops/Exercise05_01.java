/*
Write a program that reads an unspecified number of integers,
determines how many positive and negative values have been read,
and computes the total and average of the input values (not counting zeros).
Your program ends with the input 0.
Display the average as a floating-point number.
*/

import java.util.Scanner;
public class Exercise05_01
{
    public static void main(String[] args)
    {
        //Variables
        int numPositive = 0;
        int numNegative = 0;
        int numCount = 0; //for average
        int num;
        int total = 0;
        double average;
        Scanner input = new Scanner(System.in);

        //Input and Calculation
        System.out.println("Enter an integer, the input ends if it is 0: ");
        num = input.nextInt();
        if (num == 0)
        {
              System.out.println("No numbers are entered except 0");
        }
        else
        {
            while (num != 0)
            {
                if (num > 0)
                {
                    numPositive++;
                }
                else
                {
                    numNegative++;
                }

                total = total + num;
                numCount++;
                num = input.nextInt();
            }
        }

        average = total / (double)numCount; //typecast to double for correct formatting

        //Output
        System.out.println("The number of positives is " + numPositive);
        System.out.println("The number of negatives is " + numNegative);
        System.out.println("The total is " + total);
        System.out.printf("The average is %4.2f", average);
    }
}

/*
Sample Run 1
Enter an integer, the input ends if it is 0: 1 2 -1 3 0
The number of positives is 3
The number of negatives is 1
The total is 5.0
The average is 1.25


Sample Run 2
Enter an integer, the input ends if it is 0: 0
No numbers are entered except 0


Sample Run 3
Enter an integer, the input ends if it is 0: 2 3 4 5 0
The number of positives is 4
The number of negatives is 0
The total is 14
The average is 3.5


Sample Run 4
Enter an integer, the input ends if it is 0: -4 3 2 -1 0
The number of positives is 2
The number of negatives is 2
The total is 0
The average is 0.0
*/
