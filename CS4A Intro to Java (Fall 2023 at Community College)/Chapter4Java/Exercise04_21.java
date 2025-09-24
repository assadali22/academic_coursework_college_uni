/*
(Check SSN)
Write a program that prompts the user to enter a
Social Security Number in the format DDD-DD-DDDD, where D is a digit.
Your program should check whether the input is valid.


Sample Run 1
Enter a SSN: 232-23-5435
232-23-5435 is a valid social security number


Sample Run 2
Enter a SSN: 23-23-5435
23-23-5435 is an invalid social security number
Class Name: Exercise04_21

USE .INDEXOF TO FIND A CHARACTER
*/

import java.util.Scanner;
public class Exercise04_21
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String ssn;

        System.out.print("Enter a SSN: ");
        ssn = input.next();

        if ((ssn.indexOf('-') == 3) && (ssn.lastIndexOf('-') == 6)) // should be 3 == 3 && 6 == 6, the first - is in index 3, the last occurrence of - is in index 6
        {
            System.out.println(ssn + " is a valid social security number");
        }
        else
        {
            System.out.println(ssn + " is an invalid social security number");
        }
    }
}
