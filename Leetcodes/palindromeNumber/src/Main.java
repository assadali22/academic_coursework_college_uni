import java.util.Scanner;

//solved in about 17 minutes no interruptions
public class Main {
    public static void main(String[] args) {
        System.out.println("This java program determines if an integer is a palindrome number.");
        int number = 0;

        Scanner in = new Scanner(System.in);
        System.out.println("Enter an integer: ");
        number = in.nextInt();

        boolean isIntPalindrome;

        if (number < 0)
        {
            isIntPalindrome = false; // '-121' is not the same as '121-'
        }
        else
        {
            Integer numInt = Integer.valueOf(number); //convert from int type to Integer
            isIntPalindrome = palindromeNumber(numInt);
        }


        if (isIntPalindrome)
        {
            System.out.println(number + " is a palindrome");
        }
        else
        {
            System.out.println(number + " is NOT a palindrome");
        }

    }

    public static boolean palindromeNumber(Integer n)
    {

        //Integer class allows conversion into a regular string, represent the number as string
        //in order to manipulate and check for palindrome.
        // S[i] and S[length - 1], S[i + 1] and S[length - 2], etc, should be the same
        String s = n.toString();

        int startPointer = 0;
        int endPointer = s.length() - 1;

        while (startPointer < endPointer)
        {
            if (s.charAt(startPointer) != s.charAt(endPointer))
                return false;

            startPointer++;
            endPointer--;
        }

        return true;
    }
}

/*
Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.


Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore, it is not a palindrome.


Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore, it is not a palindrome.

Test Case 4:
This java program determines if an integer is a palindrome number.
Enter an integer:
55
55 is a palindrome

Test Case 5:
This java program determines if an integer is a palindrome number.
Enter an integer:
1995991
1995991 is a palindrome

Test Case 6:
This java program determines if an integer is a palindrome number.
Enter an integer:
123
123 is NOT a palindrome
 */