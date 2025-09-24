import java.util.Scanner;

public class Exercise03_01
{
    public static void main(String[] args)
    {
        //Variables
        double discriminant;
        double a, b, c;
        double r1, r2;
        Scanner input = new Scanner(System.in);

        //Input
        System.out.println("Enter a, b, c: ");
        a = input.nextDouble();
        b = input.nextDouble();
        c = input.nextDouble();

        //Calculation and Output
        discriminant = Math.pow(b, 2) - (4 * a * c);
        if (discriminant > 0)
        {
            r1 = ((-1 * b) + Math.pow(discriminant, 0.5)) / (2 * a);
            r2 = ((-1 * b) - Math.pow(discriminant, 0.5)) / (2 * a);
            System.out.println("The equation has two roots " + r1 + " and " + r2);
        }
        else if (discriminant == 0)
        {
            r1 = ((-1 * b) + Math.pow(discriminant, 0.5)) / (2 * a);
            System.out.println("The equation has one root " + r1);
        }
        else
        {
            System.out.println("The equation has no real roots");
        }


    }
}
