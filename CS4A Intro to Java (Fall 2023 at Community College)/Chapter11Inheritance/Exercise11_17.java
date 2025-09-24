import java.util.ArrayList;
import java.util.Scanner;
public class Exercise11_17
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int m;
        int n;

        System.out.print("Enter an integer m: ");
        m = input.nextInt();

        ArrayList<Integer> factors = new ArrayList<Integer>();
        n = findSmallestN(factors, m);

        System.out.println("The smallest number n for m * n to be a perfect square is " + n);
        System.out.println("m x n is " + m * n);

    }

    public static int findSmallestN(ArrayList<Integer> list, int m1)
    {
        //Find the factors
        int tempM1 = m1;
        int smallest = 1;
        while (m1 != 1)
        {
            for (int j = 2; j < tempM1; j++)
            {
                if (m1 % j == 0)
                {
                    m1 = m1 / j;
                    list.add(j);
                    break;
                }
            }
        }

        //Example: 1500 = 2 * 2 * 3 * 5 * 5 * 5 when finished with while loop
        /*
        for (int a = 0; a < list.size(); a++)
        {
          System.out.println(list.get(a));
        }
        */

        //Store factors in an array list
        ArrayList<Integer> temp = new ArrayList<Integer>();
        //Find factors that appear odd number of times
        for (int i = 0; i < list.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < list.size(); j++)
            {
                if (list.get(i) == list.get(j))
                {
                    count++;
                }
            }

            if (count % 2 != 0)
            {
                temp.add(list.get(i));
            }
        }

        //With 1500 as the example number, temp contains 3 5 5 5. Now get rid of duplicates, want 3 * 5.
        //Temp contains duplicate factors that appear odd number of times
        ArrayList<Integer> uniqueFactor = new ArrayList<Integer>();
        for (int k = 0; k < temp.size(); k++)
        {
            if (!uniqueFactor.contains(temp.get(k)))
            {
                uniqueFactor.add(temp.get(k));
            }
        }

        temp.clear();

        //Multiply the numbers that
        //appear odd number of times together
        for (int i = 0; i < uniqueFactor.size(); i++)
        {
            smallest = smallest * uniqueFactor.get(i);
        }

        return smallest;
    }
}
