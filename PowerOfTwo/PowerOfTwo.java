/*
Problem 231: Power of Two Leetcode (SOLVED)
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2^x.

Example 1:
Input: n = 1, Output = true. 2^0 = 1

Example 2:
Input: n = 16, Output = true. 2^4 = 16

Example 3:
Input: n = 3, Output = false.

Example 4:
Input n = 0, Output = false.

PASSED ALL EXAMPLES.

Started 8/27/2026, 7:10pm-7:40pm. SOLVED.
8/29/2026 8:30-8:40pm: added some test numbers with an array and tested them, it worked.

*/

import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int number;

        //int[] tests = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};
        //int[] falseTests = {324, 542, 854, 1222, 329148, 932};

        System.out.print("Enter a number to see if it is a power of 2: ");
        number = s.nextInt();

        boolean powerOfTwo = isPowerOfTwo(number);

        if (powerOfTwo)
            System.out.println("The number " + number + " is a power of two");

        else
            System.out.println(number + " is NOT a power of two");


    }

    public static boolean isPowerOfTwo(int n)
    {
        if (n == 1) return true;
        if (n < 1) return false;

        if (n % 2 == 0) return isPowerOfTwo(n / 2);
        else return false;

    }
}

