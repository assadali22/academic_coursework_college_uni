//Leetcode #50 (Medium)
//Implement pow(x, n), which calculates x raised to the n power.
//SOLVED! (completed 9/18/2026)

import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        double base = 1;
        int exponent = 1;
        Scanner s = new Scanner(System.in);

        System.out.print("Enter base: ");
        base = s.nextDouble();

        System.out.print("Enter exponent: ");
        exponent = s.nextInt();

        double result = myPow(base, exponent);

        System.out.printf("The resulting power is %.5f", result);


    }


    //x is base, n is exponent power
    public static double myPow(double x, int n)
    {
        //Base cases
        if (n == 0) return 1; //anything to 0 power is 1
        if (n == 1) return x; //anything raised to power of 1 is just the base
        if (n == -1 && x != 0) return (1 / x);

        if (x == 0 && n < 0) throw new IllegalArgumentException("Can't divide by zero.");

        if (x == 1) return 1; //1 to anything will always be one (unless its the 0 power, which is checked first)
        if (x == -1 && n % 2 == 0) return 1; // -1 to an even power will be positive
        if (x == -1 && n % 2 != 0) return -1; // -1 to an odd power will be negative


        //positive exponent
        if (n > 0)
        {
            if (n % 2 == 0)
            {
                //2^4 would become 2^2 * 2^2, cut the problem in half
                return myPow(x, n/2) * myPow(x, n/2);
            }
            else
            {
                //for 2^5, we would get 2 * 2^2 * 2^2 if n = 5
                return x * myPow(x, (n - 1) / 2) * myPow(x, (n - 1) / 2);
            }
        }
        else
        {
            //negative exponent, simply just turn the exponent into a positive while taking the reciprocal
            //for an even power, just divide by -2 since we took the reciprocal, return the positive representation
            if (n % 2 == 0)
            {
                return 1 / (myPow(x, n / -2) * myPow(x, n / -2));
            }
            else
            {
                //2^-5 -> 1 / [ 2 * myPow(2, (-5 + 1) / -2) * myPow(2, (-5 + 1) / 2) ]
                // = 1 / 2 * myPow(2,2) * myPow(2,2)
                return 1 / (x * myPow(x, (n + 1) / -2) * myPow(x, (n + 1) / -2));
            }
        }

    }
}


/*
Test Cases
Example 1: (PASSED)
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2: (PASSED)
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3: (PASSED)
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Example 4 (my own): (PASSED)
Input: x = 2, n = 7
Output: 128

Example 5 (my own): (PASSED)
Input: x = 2, n = -2
Output: 0.25

Example 6 (my own): (PASSED)
Input: x = -5, n = 3
Output: -125

Example 7 (my own): (PASSED)
Input: x = -2, n = -3
Output: 1 / -2^3 = -1/8 = -0.125

Example 8 (my own): (PASSED)
Input: x = 0, n = -5
Output: should be an exception, can't divide by 0

Example 9 (my own): (PASSED)
Input: x = -3, n = 9
Output: -19683.0000

Example 10 (my own): (PASSED)
Input: x = 1, n = 100
Output: 1

Example 11 (my own): (PASSED)
Input: x = -1, n = 99
Output: -1

Example 12 (my own): (PASSED, took 10 seconds or so for the program to finish)
Input: x = 2, n = -2147483648
Output: it's some very very small number, pretty much super close 0

Example 13 (my own): (PASSED)
Input: x = -1, n = -2147483648
Output: 1 (due to the power being even).
1 / (-1)^(2147483648) = 1 / 1 = 1.


Started 9/17/2026 3:10pm-3:30pm, 8:30pm-9:20pm
9/18/2026 10:30am-11am, tested some more test cases.
 */
