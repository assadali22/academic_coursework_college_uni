/*
(Decimal to hex) (0 1 2 3 4 5 6 7 8 9 A B C D E F)
Write a program that prompts the user to enter an int between 0 and 15 and displays its corresponding hex number.
For an incorrect input number, display invalid input.

Sample Run 1
Enter a decimal value (0 to 15): 11
The hex value is B


Sample Run 2
Enter a decimal value (0 to 15): 5
The hex value is 5


Sample Run 3
Enter a decimal value (0 to 15): 31
31 is an invalid input

*/

import java.util.Scanner;

public class Exercise04_11
{
    public static void main(String[] args)
    {
        //Variables
        int num;
        char hex = ' ';
        String numToStr;
        Scanner input = new Scanner(System.in);

        //Input
        System.out.println("Enter a decimal value (0 to 15): ");
        num = input.nextInt();

        //Calculation and Output
        if (num < 0 || num > 15)
        {
            System.out.println(num + " is an invalid input");
        }
        else
        {
            if (num >= 0 && num <= 9)
            {
                System.out.println("The hex value is " + num);
            }
            else
            {
               numToStr = num + "";

               switch (numToStr)
               {
               case "10":
                {
                    hex = 'A';
                    break;
                }

                case "11":
                {
                    hex = 'B';
                    break;
                }

                case "12":
                {
                    hex = 'C';
                    break;
                }

                case "13":
                {
                    hex = 'D';
                    break;
                }

                case "14":
                {
                    hex = 'E';
                    break;
                }

                case "15":
                {
                    hex = 'F';
                    break;
                }
               }

                System.out.print("The hex value is ");
                System.out.println(hex);
            }
        }


    }
}
