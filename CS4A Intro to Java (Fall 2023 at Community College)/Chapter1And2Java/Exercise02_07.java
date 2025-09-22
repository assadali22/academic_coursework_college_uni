/*
Write a program that prompts the user to enter the minutes (e.g., 1 billion),
and displays the number of years and days for the minutes.
For simplicity, assume a year has 365 days.

Sample Run
Enter the number of minutes: 1000000000
1000000000 minutes is approximately 1902 years and 214 days

*/

import java.util.Scanner;

public class Exercise02_07
{
    public static void main(String[] args)
    {
        //Variables and Input
        int minuteInput;
        int years; //this is displayed
        int days;
        int remainingDays; //this is displayed
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the number of minutes: ");
        minuteInput = input.nextInt();

        //Calculation
        days = minuteInput / 60 / 24; //conversion to days
        years = days / 365;
        remainingDays = days % 365;

        //Output
        System.out.println(minuteInput + " minutes is approximately " + years + " years and " + remainingDays + " days");

    }
}
