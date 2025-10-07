/*
Given a string s, return the longest palindromic substring in s.
SOLVED!
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

My test cases:
"abrbadaadab" (longest is badaadab, not abrba) (PASSED)
"fhxabaxaom" (xabax is longest) (PASSED)
"yufnnplpnn" (should be nnplpnn, not nn) (PASSED)
"thetacocatisnice" (longest is tacocat) (PASSED)

10/3/2025: 1.5 hour spent, no luck
30 min troubleshooting

10/6/2025: 30 min debugging, got it to work!
Total time: 2 and a half hours
*/
import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        Scanner stringScan = new Scanner(System.in);
        String str;

        System.out.println("Enter a string:");
        str = stringScan.next();

        String palindrome = longestPalindrome(str);
        System.out.println(palindrome);

    }


    public static String longestPalindrome(String s)
    {
        int strLength = s.length();

        //define a 2D memo table representing the start and end index. Stores length of palindromic substring
        //At some index i, j, a substring, what is the longest palindromic substring
        //Goal: largest value in memo table
        int[][] memo = new int[strLength][strLength];

        //Set all values to -99
        for (int i = 0; i < memo.length; i++)
        {
            for (int j = 0; j < memo[i].length; j++)
            {
                memo[i][j] = -99;
            }
        }

        //Diagonals are 0
        int i = 0;
        while (i < strLength)
        {
            memo[i][i] = 0;
            i++;
        }

        //fill memo table and solve sub-problems, no need to return anything
        longestPalindromeHelper(s, memo, 0, strLength - 1);

        int largest = memo[0][0];
        int largestStart = 0;
        int largestEnd = 0;

        //find the longest length in memo table, store those indices
        //which represent starting and ending index for longest palindrome substring
        for (int m = 0; m < memo.length; m++)
        {
            for (int j = 0; j < memo[m].length; j++)
            {
                if (memo[m][j] > largest)
                {
                    largest = memo[m][j];
                    largestStart = m;
                    largestEnd = j;
                }
            }
        }

        return s.substring(largestStart, largestEnd + 1);
    }

    public static void longestPalindromeHelper(String s, int[][] memo, int start, int end)
    {
        if (start >= end) return;
        if (memo[start][end] != -99) return;

        int startPointer = start;
        int endPointer = end;

        //check for palindrome
        while (startPointer < endPointer)
        {
            if (s.charAt(startPointer) != s.charAt(endPointer))
            {
                //if characters differ, not a palindrome, set memo for that location to be 0
                //then break out of the loop
                memo[start][end] = 0;
                break;
            }
            startPointer++;
            endPointer--;

        }

        //if we go through the while loop successfully without breaking
        //then the string is a palindrome
        if (startPointer == endPointer || startPointer > endPointer)
            memo[start][end] = s.substring(start, end + 1).length();

        //memo[start][end] = s.length() is wrong.
        //s.length() looks at ORIGINAL string, want to find length of substring.
        //Take the SUBSTRING then get the length. 2nd parameter not inclusive, need to add 1


        //just pass in original string repeatedly, don't pass substring
        //Passing substring in recursive call caused inconsistent indices
        //between start/end and modified string
        longestPalindromeHelper(s, memo, start + 1, end);

        longestPalindromeHelper(s, memo, start + 1, end - 1);

        longestPalindromeHelper(s, memo, start, end - 1);

        return;
    }
}
