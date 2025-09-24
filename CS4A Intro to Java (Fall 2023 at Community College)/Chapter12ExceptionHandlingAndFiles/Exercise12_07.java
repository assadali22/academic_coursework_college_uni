import java.util.Scanner;
public class Exercise12_07
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String s;
        int num = 0;
        System.out.println("Enter a binary number: ");
        s = input.next();

        try
        {
            num = bin2Dec(s);
            System.out.println(num);
        }
        catch(NumberFormatException ex)
        {
            System.out.println(ex);
        }

    }


    public static int bin2Dec(String binaryString) throws NumberFormatException
    {
        int binaryNum = 0;
        int i;
        int j;
        int stringToNum;
        String charToString;
        //Check if the number is binary
        for (i = 0; i < binaryString.length(); i++)
        {
            if (binaryString.charAt(i) != '0' && binaryString.charAt(i) != '1')
            {
                throw new NumberFormatException(binaryString);
            }
        }

        //Find decimal number
        for (i = binaryString.length() - 1, j = 0; i >= 0 && j < binaryString.length(); i--, j++)
        {
            charToString = "" + binaryString.charAt(i);
            stringToNum = Integer.parseInt(charToString);
            binaryNum = binaryNum + (stringToNum * (int)(Math.pow(2, j)));
        }

        return binaryNum;
    }
}



class NumberFormatException extends Exception
{
    private String invalid;

    public NumberFormatException(String s1)
    {
        super("Not a binary number: " + s1);
        invalid = s1;
    }
}
