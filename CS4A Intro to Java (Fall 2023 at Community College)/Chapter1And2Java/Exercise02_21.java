/*
Write a program that reads in investment amount, annual interest rate, and number of years,
and displays the future investment value using the following formula:
futureInvestmentValue = investmentAmount * (1 + monthlyInterestRate)^(numberOfYears * 12)
For example, if you enter amount 1000, annual interest rate 3.25%,
and number of years 1, the future investment value is 1032.98.
*/

import java.util.Scanner;

public class Exercise02_21
{
    public static void main(String[] args)
    {
        //Variables
        double investmentAmount;
        double annualInterestRate;
        double monthlyInterestRate;
        int numberOfYears;
        double futureInvestmentValue;
        Scanner input = new Scanner(System.in);

        //Input
        System.out.print("Enter investment amount: ");
        investmentAmount = input.nextDouble();

        System.out.print("Enter annual interest rate in percentage: ");
        annualInterestRate = input.nextDouble();

        System.out.print("Enter number of years: ");
        numberOfYears = input.nextInt();

        //Calculation
        monthlyInterestRate = (annualInterestRate / 12) / 100;
        futureInvestmentValue = investmentAmount * Math.pow(1 + monthlyInterestRate, numberOfYears * 12);

        //Output
        System.out.println("Future value is: " + futureInvestmentValue);
    }
}
