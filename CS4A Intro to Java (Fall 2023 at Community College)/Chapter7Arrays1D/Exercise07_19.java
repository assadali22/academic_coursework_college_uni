/*
(Sorted?)
Write the following method that returns true
if the list is already sorted in increasing order.
public static boolean isSorted(int[] list)
Write a test program that prompts the user to enter a list
and displays whether the list is sorted or not.
Here is a sample run. Note that the first number in the input
indicates the number of the elements in the list. This number is not part of the list.


Sample Run 1
Enter list: 8 10 1 5 16 61 9 11 1
The list is not sorted
Sample Run 2
Enter list: 10 1 1 3 4 4 5 7 9 11 21
The list is already sorted
*/

import java.util.Scanner;
public class Exercise07_19
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int size;
        int i;
        int number;
        boolean sorted;
        System.out.print("Enter list: ");
        size = input.nextInt();

        int[] arr = new int[size];
        for (i = 0; i < size; i++)
        {
            number = input.nextInt();
            arr[i] = number;
        }

        sorted = isSorted(arr);

        if (sorted)
        {
            System.out.println("The list is already sorted");
        }
        else
        {
           System.out.println("The list is not sorted");
        }
    }


    public static boolean isSorted(int[] list)
    {
        int i;
        for (i = 0; i < list.length - 1; i++)
        {
            if (list[i] > list[i + 1])
            {
                return false;
            }
        }

        return true;
    }
}
