import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

//(SOLVED!)

public class Main
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numberInput = 0;

        //sample arrays
        int[] inputArray = {5, 24, 54, 12, 16};
        int[] sampleArrayOne = {2, 7, 11, 15};
        int[] sampleArrayTwo = {3, 2, 4};
        int[] sampleArrayThree = {3, 3};

        System.out.print("Input array: ");
        for (int j = 0; j < inputArray.length; j++)
            System.out.print(inputArray[j] + " ");

        System.out.println();
        System.out.print("Enter a target number for two sum problem: ");
        numberInput = in.nextInt();

        int[] answerIndices = twoSumProblem(inputArray, numberInput);

        if (answerIndices.length == 2)
            System.out.println("Indices for unsorted array: " + answerIndices[0] + ", " + answerIndices[1]);
        else
            System.out.println("No solution");
    }

    public static int[] twoSumProblem(int[] arr, int target)
    {
        //case if array length is 2
        if (arr.length == 2)
        {
            if (arr[0] + arr[1] == target)
                return new int[]{0, 1};
            else
                return new int[]{-1}; //no solution
        }

        //2D array to store values + original index in the unsorted array
        int[][] arrWithOriginalIndex = new int[arr.length][2];

        //length of number of rows, which is arrWithOriginalIndex.length
        //for example, if we have 5 numbers in the array, there are 5 rows.
        //With {5, 24, 54, 12, 16}, we get {{5, 0}, {24, 1}, {54, 2}, {12, 3}, {16, 4}}
        for (int i = 0; i < arrWithOriginalIndex.length; i++)
        {
            arrWithOriginalIndex[i][0] = arr[i]; //value in first column
            arrWithOriginalIndex[i][1] = i; //original index in 2nd column
        }

        //sort from least to greatest
        Arrays.sort(arrWithOriginalIndex, Comparator.comparingInt(x -> x[0]));
        //(x, y) -> Integer.compare(x[0], y[0]) was replaced with comparingInt(x -> x[0]) by Intellij.
        //This sorts by the first column, which are the values to sort.

        //debug to check for sorted array (works)
        //System.out.print("Result of sorting: ");
        //for (int j = 0; j < arrWithOriginalIndex.length; j++)
        //    System.out.print(arrWithOriginalIndex[j][0] + " ");
        //System.out.println();

        //Use two pointers. If the sum of start and end value match the target,
        //return original indices from unsorted array.
        //If sum at start and end is too large, we move the end pointer down
        //Otherwise, add 1 to the start pointer
        int start = 0;
        int end = arrWithOriginalIndex.length - 1;

        while (start < end)
        {
            if (arrWithOriginalIndex[start][0] + arrWithOriginalIndex[end][0] == target)
            {
                return new int[]{arrWithOriginalIndex[start][1], arrWithOriginalIndex[end][1]};
            }
            else if (arrWithOriginalIndex[start][0] + arrWithOriginalIndex[end][0] > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        return new int[]{-1};

    }

}


/*
Leetcode: Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice. You can return the answer in any order.

Started 6/15/2026 11:45am - 12pm

Returned 8/20/2026: 6:15pm - 7:30pm. (SOLVED!)

could sort the array and throw away values that are larger than target, but
that might mess up what the leetcode test expects. It might use index from original array,
which is going to be different from the sorted array as
the indices will differ if the array is modified and sorted.

Or, make a 2D array, storing the original index of the unsorted array. (yes!)
arr[0] is the number, arr[1] is the original index.

Then, with the array sorted, use two pointers at the start and end.
If sum is too big, move the end pointer down by 1 (decrement)
If sum is too small, move the starting pointer up 1 (increment)

Test Cases
Input array: 5 24 54 12 16, target = 28 (should get index 3 and 4, because 12 + 16 = 28)
(PASSED)

Input array: 5 24 54 12 16, target = 29 (should get index 0 and 1). (PASSED)

Input array: 5 24 54 12 16, target = 13 (should get no solution). (PASSED)

Input array: {2, 7, 11, 15}, target = 9, answer should be [0, 1] (PASSED)
Input array: {3, 2, 4}, target = 6, answer should be [1, 2] (PASSED)
Input array: {3, 3}, target = 6, answer should be [0, 1] (PASSED)

*/
