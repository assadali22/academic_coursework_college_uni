/*
(Count occurrence of numbers)
Write a program that reads the integers between 1 and 100 and counts the occurrences of each.
Assume the input ends with 0.


Sample Run
Enter the integers between 1 and 100: 2 5 6 5 4 3 23 43 2 0
2 occurs 2 times
3 occurs 1 time
4 occurs 1 time
5 occurs 2 times
6 occurs 1 time
23 occurs 1 time
43 occurs 1 time
Note that if a number occurs more than one time, the plural word "times" is used in the output. Also note that the numbers are displayed in increasing order.
*/

import java.util.Scanner;
public class Exercise07_03
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int num;
        int i = 0;

        //Array to represent how many times a number occurs
        int[] occurs = new int[100];

        System.out.print("Enter the integers between 1 and 100: ");
        num = input.nextInt();


        while (num != 0)
        {
            if (num >= 1 && num <= 100) //check to make sure we are in the bound of the array index
            {
                //increment occurence of a number by 1. If num was 3, value of num[2] goes up by 1.
                occurs[num - 1]++;
                num = input.nextInt();
            }

        }

        //Display number of occurrences
        for (i = 0; i < occurs.length; i++)
        {
            if (occurs[i] > 0) //print number if it occurs at least once
            {
                System.out.print((i + 1) + " occurs " + occurs[i]);
                if (occurs[i] > 1)
                {
                    System.out.println(" times");
                }
                else if (occurs[i] == 1) //if there is one instance of a number
                {
                    System.out.println(" time");
                }
            }
        }

    }
}
