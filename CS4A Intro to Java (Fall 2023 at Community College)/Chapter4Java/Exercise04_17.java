/*
(Days of a month)
Write a program that prompts the user to enter a year and the first three letters of a month name
(with the first letter in uppercase) and displays the number of days in the month.
If the input for month is incorrect, display a message as shown in the following sample run.

Sample Run 1
Enter a year: 2001
Enter a month: Jan
Jan 2001 has 31 days


Sample Run 2
Enter a year: 2016
Enter a month: Feb
Feb 2016 has 29 days


Sample Run 3
Enter a year: 2016
Enter a month: jan
jan is not a correct month name
*/

import java.util.Scanner;
public class Exercise04_17
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int year;
        String month;

        System.out.println("Enter a year: ");
        year = input.nextInt();

        System.out.println("Enter a month: ");
        month = input.next();

        switch (month)
        {
            case "Jan":
            {
                System.out.println(month + " " + year + "has 31 days");
                break;
            }

            case "Feb":
            {
                //Check if the year is a leap year
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                {
                    System.out.println(month + " " + year + "has 29 days");
                }
                else
                {
                    System.out.println(month + " " + year + "has 28 days");
                }
                break;
            }

            case "Mar":
            {
                System.out.println(month + " " + year + "has 31 days");
                break;
            }

            case "Apr":
            {
                System.out.println(month + " " + year + "has 30 days");
                break;
            }

            case "May":
            {
                System.out.println(month + " " + year + "has 31 days");
                break;
            }

            case "Jun":
            {
                System.out.println(month + " " + year + "has 30 days");
                break;
            }

            case "Jul":
            {
                System.out.println(month + " " + year + "has 31 days");
                break;
            }

            case "Aug":
            {
                System.out.println(month + " " + year + "has 31 days");
                break;
            }

            case "Sep":
            {
                System.out.println(month + " " + year + "has 30 days");
                break;
            }

            case "Oct":
            {
                System.out.println(month + " " + year + "has 31 days");
                break;
            }

            case "Nov":
            {
                System.out.println(month + " " + year + "has 31 days");
                break;
            }

            case "Dec":
            {
                System.out.println(month + " " + year + "has 31 days");
                break;
            }


            default:
            {
                System.out.println(month + " is not a correct month name");
            }
        }
    }
}
