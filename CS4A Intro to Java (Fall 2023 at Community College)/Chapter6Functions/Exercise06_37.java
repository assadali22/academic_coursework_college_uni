/*
(Format an integer)
Write a method with the following header to format the integer with the specified width.
public static String format(int number, int width)

The method returns a string for the number with one or more prefix 0s. The size of the string is the width.
For example,
format(34, 4) returns 0034
format(34, 5) returns 00034


If the number is longer than the width, the method returns the string representation for the number.
For example,
format(34, 1) returns 34
Write a test program that prompts the user to enter a number and its width
and displays a string returned by invoking format(number, width).


Sample Run
Enter an Integer: 34
Enter the width: 5
The formatted number is 00034
*/

import java.util.Scanner;
public class Exercise06_37
{
    public static void main(String[] args)
    {
        //Variables
        Scanner input = new Scanner(System.in);
        int numInput;
        int w;
        String formatNum;

        //Input
        System.out.print("Enter an Integer: ");
        numInput = input.nextInt();
        System.out.print("Enter the width: ");
        w = input.nextInt();

        //Function Call and Output
        formatNum = format(numInput, w);
        System.out.println("The formatted number is " + formatNum);
    }

    public static String format(int number, int width)
    {
        String numStr = number + "";
        int length = numStr.length();
        if (numStr.length() > width) //return original number if it is longer than width
        {
            return numStr;
        }
        else
        {
            int i;
            for (i = 1; i <= width - length; i++)
            {
                numStr = "0" + numStr; //add 0 to the start of the string
            }

            return numStr;
        }
    }
}
