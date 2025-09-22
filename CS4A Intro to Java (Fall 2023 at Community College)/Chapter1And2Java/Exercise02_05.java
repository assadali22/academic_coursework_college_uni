/*
Write a program that reads the subtotal and the gratuity rate, then computes the gratuity and total.
For example, if the user enters 10 for subtotal and 15% for gratuity rate, the program displays $1.5 as gratuity and $11.5 as total.
Sample Run
Enter the subtotal and a gratuity rate: 10 15
The gratuity is $1.5 and total is $11.5
*/

import java.util.Scanner;
public class Exercise02_05
{
    public static void main(String[] args)
    {
        //Variables
        double gratuityRate; //whole number entered
        double subtotal;
        double total;
        double tip;

        //Input
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the subtotal and a gratuity rate: ");
        subtotal = input.nextDouble();
		gratuityRate = input.nextDouble();
        

        //Calculation
        tip = (gratuityRate / 100) * subtotal;
        total = subtotal + tip;

        //Output
        System.out.println("The gratuity is $" + tip + " and total is $" + total);

    }
}
