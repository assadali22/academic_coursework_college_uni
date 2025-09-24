import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        int numLines = 0;
        long numChars = 0;
        int numWords = 0;

        File f1 = new File(args[0]);
        Scanner fInput = new Scanner(f1);


        //Count characters, words, and lines
        numChars = f1.length();
        while (fInput.hasNext())
        {
            fInput.next();
            numWords++;
        }

        //Close and reopen the file
        fInput.close();

        fInput = new Scanner(f1);
        while (fInput.hasNext())
        {
            fInput.nextLine();
            numLines++;
        }

        //Output total characters words and lines
        System.out.println(numChars + " characters");
        System.out.println(numWords + " words");
        System.out.println(numLines + " lines");


    }
}
