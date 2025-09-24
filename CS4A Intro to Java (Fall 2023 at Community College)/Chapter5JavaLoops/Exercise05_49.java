/*
Count vowels and consonants)
Assume letters A, E, I, O, and U as the vowels.
Write a program that prompts the user to enter a string
and displays the number of vowels and consonants in the string.

Sample Run
Enter a string: Programming is fun
The number of vowels is 5
The number of consonants is 11

*/

import java.util.Scanner;
public class Exercise05_49
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int i;
        int numVowels = 0;
        int numConsonants = 0;
        int length;
        String s;
        char ch;

        System.out.print("Enter a string: ");
        s = input.nextLine();
        length = s.length();
        for (i = 0; i < length; i++)
        {
            ch = Character.toUpperCase(s.charAt(i));
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                numVowels++;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                numConsonants++;
            }
        }

        System.out.println("The number of vowels is " + numVowels);
        System.out.println("The number of consonants is " + numConsonants);

    }
}
