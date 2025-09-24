/*
(Print distinct numbers)
Write a program that reads in ten numbers and displays the number of
distinct numbers and the distinct numbers separated by exactly one space
(i.e., if a number appears multiple times, it is displayed only once).

(Hint: Read a number and store it to an array if it is new. If the number is already in the array, ignore it.)
After the input, the array contains the distinct numbers in the order of their input.


Sample Run
Enter ten numbers: 1 2 3 2 1 6 3 4 5 2
The number of distinct number is 6
The distinct numbers are: 1 2 3 6 4 5
*/

import java.util.Scanner;
public class Exercise07_05
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int num;
        int i;
        int distinctValues = 0;
        int[] arr = new int[10];

        System.out.print("Enter ten numbers: ");
        num = input.nextInt();
        arr[0] = num;
        distinctValues++;
        for (i = 1; i < arr.length; i++)
        {
            num = input.nextInt();
            if (!(search(arr, num))) //add new number to the array if it is unique (if it isn't in the array already)
            {
                arr[distinctValues] = num;
                distinctValues++;
            }
        }

        //Print distinct numbers
        System.out.println("The number of distinct number is " + distinctValues);
        System.out.print("The distinct numbers are: ");
        for (i = 0; i < arr.length; i++)
        {
            System.out.print(arr[i] + " ");
        }
    }

    public static boolean search(int[] arr, int target)
    {
        int j;
        for (j = 0; j < arr.length; j++)
        {
            if (target == arr[j])
            {
                return true;
            }
        }


        return false;
    }
}
