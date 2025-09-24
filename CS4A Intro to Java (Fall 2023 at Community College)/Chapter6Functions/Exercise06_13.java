/*
Sum series)
Write a method to compute the following series:
m(i) = 1/2 + 2/3 +......+ i/(i+1)
Write a test program that displays the following table:
i       m(i)
1      0.5000
2      1.1667
...
19    16.4023
20    17.3546

*/

public class Exercise06_13
{
    public static void main(String[] args)
    {
        int terms = 20;
        sumSeries(terms);
    }

    public static void sumSeries(int k)
    {
        int i;
        double total = 0;
        System.out.println("i       m(i)");
        for (i = 1; i <= k; i++)
        {
            total = total + (i / (double)(i + 1)); //typecast to double for correct decimal division, prevent integer division
            System.out.printf("%d      %.4f\n", i, total);
        }
    }
}

