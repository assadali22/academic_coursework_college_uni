import java.util.Scanner;

public class Exercise03_23
{
    public static void main(String[] args)
    {
        //Variables
        Scanner input = new Scanner(System.in);
        double x, y;

        //Input
        System.out.println("Enter a point with two coordinates: ");
        x = input.nextDouble();
        y = input.nextDouble();

        if ((x < 5.0 && x > -5.0) && (y < 2.5 && y > -2.5))
        {
            System.out.println("Point (" + x + ", " + y + ") is in the rectangle");
        }
        else
        {
            System.out.println("Point (" + x + ", " + y + ") is not in the rectangle");
        }
    }

}
