/*
Write a method that converts milliseconds to hours, minutes,
and seconds using the following header:
public static String convertMillis(long millis)

The method returns a string as hours:minutes:seconds.

For example,
convertMillis(5500)returns a string 0:0:5,
convertMillis(100000) returns a string 0:1:40
convertMillis(555550000) returns a string 154:19:10.

Write a test program that prompts the user to enter a long integer for
milliseconds and displays a string in the format of hours:minutes:seconds.


Sample Run
Enter time in milliseconds: 555550000
154:19:10
*/

import java.util.Scanner;
public class Exercise06_25
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        long millisecondInput;

        System.out.print("Enter time in milliseconds: ");
        millisecondInput = input.nextLong();

        System.out.println(convertMillis(millisecondInput));
    }

    public static String convertMillis(long millis)
    {
        String time;
        int hours;
        int minutes;
        int seconds;
        int remainingSeconds;
        int remainingMin;

        seconds = (int)(millis) / 1000;
        remainingSeconds = seconds % 60; //account for a 0-59 seconds to be displayed
        minutes = seconds / 60;
        remainingMin = minutes % 60; //number between 0-59 shows up for minutes
        hours = minutes / 60;


        time = hours + ":" + remainingMin + ":" + remainingSeconds;
        return time;
    }

}
