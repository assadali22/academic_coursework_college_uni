/*
(Remove duplicates)
Write a method that removes the duplicate elements from an array list of integers using the following header:
public static void removeDuplicate(ArrayList<Integer> list)
Write a test program that prompts the user to enter 10 integers to
a list and displays the distinct integers in their input order separated by exactly one space.


Sample Run 1
Enter ten integers: 34 5 3 5 6 4 33 2 2 4
The distinct integers are 34 5 3 6 4 33 2

Sample Run 2
Enter ten integers: 3 3 4 4 1 1 2 2 5 5
The distinct integers are 3 4 1 2 5

Sample Run 3
Enter ten integers: 1 2 2 3 4 5 6 7 8 8
The distinct integers are 1 2 3 4 5 6 7 8

Sample Run 4
Enter ten integers: 5 4 3 2 65 4 4 5 1 5
The distinct integers are 5 4 3 2 65 1

*/

import java.util.Scanner;
import java.util.ArrayList;
public class Exercise11_13
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int num;
        ArrayList<Integer> arrInt = new ArrayList<Integer>();
        System.out.print("Enter ten integers: ");
        for (int i = 0; i < 10; i++)
        {
            num = input.nextInt();
            arrInt.add(num);
        }

        removeDuplicate(arrInt);


        System.out.println("The distinct integers are ");
        for (int i = 0; i < arrInt.size(); i++)
        {
            System.out.print(arrInt.get(i) + " ");
        }


    }

    public static void removeDuplicate(ArrayList<Integer> list)
    {
        ArrayList<Integer> temp = new ArrayList<Integer>();

        //Put unique elements in temporary array list (hashing method?)
        for (int j = 0; j < list.size(); j++)
        {
            if (!temp.contains(list.get(j)))
            {
                temp.add(list.get(j));
            }
        }

        //Clear original list
        list.clear();


        //Assign unique elements to original list
        for (int j = 0; j < temp.size(); j++)
        {
            list.add(temp.get(j));
        }
    }
}
