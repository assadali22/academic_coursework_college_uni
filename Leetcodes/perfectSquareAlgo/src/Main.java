import java.util.ArrayList;
import java.util.Scanner;
import java.math.*;

//not solved.. "completed" 9/13/2025
//last modified 10/21/2026, 553 out of 589 test cases passed, 
//with an annoying test case of 70 blocking success (previous implementation with 1D memo)

//last modified 10/22/2026, major logic modification and accepted on leetcode 10/22/2026
public class Main {
    public static void main(String[] args) {
        System.out.println("Enter an int to show number of least perfect squares: ");
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int result = numSquares(n);
        System.out.println(result);

    }

    public static int numSquares(int n) {
        if (n < 0 || n > 10000) return -1;
        ArrayList<Integer> temp = new ArrayList<>();

        int i = 1;
        while (i * i <= n)
        {
            temp.add(i * i);
            i++;
        }

        //2D memo for amount and corresponding index from perfect squares array
        int[][] memo = new int[n + 1][squares.size()];
        for (int k = 0; k < n + 1; k++)
        {
            memo[k][0] = k;  //for any amount, given only 1s, its just the amount itself
            for (int j = 1; j < squares.size(); j++)
            {
                memo[k][j] = 10001;
            }
        }
        
        return findLeastSquares(n, temp, memo, temp.size() - 1);
    }

    
    public static int findLeastSquares(int a, ArrayList<Integer> squares, int[][] memo, int coinIndex)
    {
        if (memo[a][coinIndex] != 10001) return memo[a][coinIndex]; //a solution to subproblem is already filled
        if (coinIndex == 0) return a; //rest will use 1s

        //we can say, worst case to make the amount is a coins, consisting of 1s
        //helpful video: https://www.youtube.com/watch?v=5roBh-lns4M
        int keep = a; //SET KEEP EQUAL TO AMOUNT, NOT 0 (otherwise 0 ruins everything)
        int skip;

        //take that square number, subtract from amount a
        if (a - squares.get(coinIndex) >= 0)
            keep = findLeastSquares(a - squares.get(coinIndex), squares, memo, coinIndex);
        

        skip = findLeastSquares(a, squares, memo, coinIndex - 1); //skip and move to the next square number
        memo[a][coinIndex] = Math.min(skip, 1 + keep);
        return memo[a][coinIndex];
    }

}

//fix: set keep equal to amount (counter-intuitive, thought skip would be the amount, but at least it works)

/*
#279 Perfect Squares Leetcode
Given an integer n, return the least number of perfect squares that sum to n.
A perfect square is an integer that is the square of an integer (aka the product of some integer with itself)
Ex: 1, 4, 9, 16, 25, 36

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
(taking 9 with greedy approach does NOT work, 9 + 1 + 1 + 1 uses 4 coins)

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

21 = 16 + 4 + 1 (should be 3, NOT 2)
15 = 9 + 4 + 1 + 1 (should be 4, NOT 2)
122 = 121 + 1 (11^2 + 1^2), 2 coins as expected
112 = 100 + 4 + 4 + 4 (4 coins)

*/


//what was this youtuber even on about when talking about "number of ways", seriously
//this literally caused MAJOR CONFUSION when I was trying to solve the problem above
//using an array of perfect squares, so annoying oh my god
/*
//didnt even work, not even works similar to dynamic programming video from DecodingIntuition
    public static int findLeastSquares(int n, ArrayList<Integer> squares, int start)
    {
        if (n < 0) return 0;
        if (n == 1) return 1;
        if (start == 0)
        {
            if (n == 0) return 1;
            else return 0;
        }

        int keep = 0;
        int skip;
        if (n - squares.get(start) >= 0)
            keep = findLeastSquares(n - squares.get(start), squares, start - 1);

        skip = findLeastSquares(n, squares, start - 1);
        return keep + skip;
    }
 */
