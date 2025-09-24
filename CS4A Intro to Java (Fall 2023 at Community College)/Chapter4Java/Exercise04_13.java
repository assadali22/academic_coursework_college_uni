/*
Write a program that prompts the user to enter a letter and
check whether the letter is a vowel or consonant.

For a nonletter input, display invalid input.
Sample Run 1
Enter a letter: B
B is a consonant


Sample Run 2
Enter a letter grade: a
a is a vowel


Sample Run 3
Enter a letter grade: #
# is an invalid input

*/

import java.util.Scanner;
public class Exercise04_13
{
    public static void main(String[] args)
    {
        String s; //In java, read the character into a string, then use the charAt method so you can store the character in a char variable.
        char chInput;
        Scanner input = new Scanner(System.in);

        System.out.println("Enter a letter grade: ");
        s = input.nextLine();
        chInput = s.charAt(0);

        if ((chInput >= 'A' && chInput <= 'Z') || (chInput >= 'a' && chInput <= 'z'))
        {
            if ((Character.toLowerCase(chInput) == 'a') || (Character.toLowerCase(chInput) == 'e') || (Character.toLowerCase(chInput) == 'i') || (Character.toLowerCase(chInput) == 'o') || (Character.toLowerCase(chInput) == 'u'))
            {
                System.out.println(chInput + "is a vowel");
            }
            else
            {
                System.out.println(chInput + "is a consonant");
            }
        }
        else
        {
            System.out.println(chInput + "is an invalid input");
        }
    }
}

