/*
Leetcode 11: Container with Most Water (SOLVED!)

You are given an integer array height of length n.
There are n vertical lines drawn such that the two endpoints of the ith line
are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container,
such that the container contains the most water.

Return the maximum amount of water a container can store. The container can't be slanted.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: Vertical lines of a bar chart are represented by array [1,8,6,2,5,4,8,3,7].
(first bar is 1, 2nd bar is 8, 3rd bar is 6, and so on)
In this case, the max area of water the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Example 3 (my own):
Input: [4, 1, 6, 5, 1, 2]
Output: 12 (start = 0, end = 3) after drawing in Paint
(PASSED)

Example 4 (my own):
Input: [2, 5, 9, 3, 6, 1, 5]
Output: 25 (start = 1, end = 6) after drawing in Paint
(PASSED)

*/

import java.lang.Math;

public class Main
{
    public static void main(String[] args)
    {
        int[] arr1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int[] arr2 = {1,1};
        int[] arr3 = {4, 1, 6, 5, 1, 2};
        int[] arr4 = {2, 5, 9, 3, 6, 1, 5};

        System.out.print("Array is ");

        for (int x = 0; x < arr4.length; x++)
            System.out.print(arr4[x] + " ");

        System.out.println();

        int area = maxArea(arr4);
        System.out.println("Max area for water container for this array is " + area);


    }

    public static int maxArea(int[] arr)
    {
        int largestArea = 0;
        int currentArea = 0;
        int start = 0;
        int end = arr.length - 1;

        //Use two pointers to traverse the array. To find the area, the length
        //will be the difference between start and end pointers (end minus start).
        //Height is the minimum between the value at arr[start] and arr[end] to avoid slanting/overflow

        while (start < end)
        {
            currentArea = (end - start) * Math.min(arr[end], arr[start]);

            if (currentArea > largestArea)
                largestArea = currentArea; //update the largest area if we did better

            //if end pointer has smaller value, decrement it
            //otherwise, if the start pointer has the smaller value, increment it.
            if (arr[end] < arr[start])
                end--;
            else
                start++;
        }

        return largestArea;
    }
}


//Started 10/1/2026 at 11am. Completed after an hour. SOLVED!
