import java.util.Scanner;
public class Exercise06_07
{
    public static void main(String[] args)
    {
        //Variables
        Scanner input = new Scanner(System.in);
        double amountInvested;
        double annualInterest;
        double monthlyInterestRate;
        double futureInvestment;
        int years;

        //Input
        System.out.print("The amount invested: ");
        amountInvested = input.nextDouble();

        System.out.print("Annual interest rate: ");
        annualInterest = input.nextDouble();

        monthlyInterestRate = annualInterest / 12 / 100;
        //Output
        System.out.println("Years Future Value");
        for (years = 1; years <= 30; years++)
        {
            futureInvestment = futureInvestmentValue(amountInvested, monthlyInterestRate, years);
            System.out.printf("%d\t%.2f\n", years, futureInvestment);
        }
    }

    public static double futureInvestmentValue(double investmentAmount, double monthlyInterestRate, int years)
    {
        //Calculation
        double futureValue;
        futureValue = investmentAmount *  Math.pow(1 + monthlyInterestRate, years * 12);
        return futureValue;
    }
}
