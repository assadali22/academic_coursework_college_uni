/*
Write a program that passes an unspecified number of integers from command line and displays their total.
Sample Run 1
command>java 1 2 3 4 5
The total is 15
Sample Run 2
command>java 1 9 1 1 1
The total is 13
*/

public class Exercise07_21
{
    public static void main(String[] args)
    {
        int i;
        int sum = 0;

        for (i = 0; i < args.length; i++)
        {
            sum = sum + Integer.parseInt(args[i]);
        }

        System.out.println("The total is " + sum);
    }
}
