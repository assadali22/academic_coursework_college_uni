/*
Write a method that finds the number of occurrences of a
specified character in a string using the following header:
public static int count(String str, char a)

For example, count("Welcome", 'e') returns 2.
Write a test program that prompts the user to enter a string
followed by a character and displays the number of occurrences of the character in the string.


Sample Run
Enter a string: We the people
Enter a character: e
The number of occurrences of e in We the people is 4
*/

import java.util.Scanner;
public class Exercise06_23
{
    public static void main(String[] args)
    {
        //Variables
        Scanner input = new Scanner(System.in);
        String userIn;
	    String charIn; //read the char
        char ch;
        int charCount;

        //Input
        System.out.print("Enter a string: ");
        userIn = input.nextLine();
        System.out.print("Enter a character: ");
        charIn = input.nextLine();
	    ch = charIn.charAt(0); //get the char from the string variable

	    //Function call and Output
	    charCount = count(userIn, ch);
	    System.out.println("The number of occurrences of " + ch + " in " + userIn + " is " + charCount);
    }

    public static int count(String str, char a)
    {
        int count = 0;
        int length = str.length();
        int i;

        for (i = 0; i < length; i++)
        {
            if (str.charAt(i) == a)
            {
                count++;
            }
        }

        return count;
    }
}
