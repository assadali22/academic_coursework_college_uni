/*
(Financial application: compare loans with various interest rates)
Write a program that lets the user enter the loan amount and loan
period in number of years and displays the monthly and total payments for
each interest rate starting from 5% to 8%, with an increment of 1/8.
Sample Run
Loan Amount: 10000
Number of Years: 5
Interest Rate      Monthly Payment     Total Payment
5.000%             188.71              11322.74
5.125%             189.29              11357.13
5.250%             189.86              11391.59
....
7.875%             202.17              12129.97
8.000%             202.76              12165.84
*/

import java.util.Scanner;
public class Exercise05_21
{
    public static void main(String[] args)
    {
        //Variables
        Scanner input = new Scanner(System.in);
        double loanAmount;
        int numYears;

        double interestRate;
        double monthlyPayment;
        double totalPayment;
        double monthlyInterest;

        //Input
        System.out.println("Loan Amount: ");
        loanAmount = input.nextDouble();

        System.out.println("Number Of Years: ");
        numYears = input.nextInt();

        //Output
        System.out.printf("%-20s%-20s%-20s\n", "Interest Rate", "Monthly Payment", "Total Payment");
        for (interestRate = 5.0; interestRate <= 8.0; interestRate += (1.0 / 8))
        {
            //Calculation
            monthlyInterest = (interestRate / 12) / 100;
            monthlyPayment = (loanAmount * monthlyInterest) / (1 - (1 / Math.pow(1 + monthlyInterest, numYears * 12)));
            totalPayment = monthlyPayment * numYears * 12;

            System.out.printf("%-20.3f%-20.3f%-20.3f\n", interestRate, monthlyPayment, totalPayment);
        }
    }
}
