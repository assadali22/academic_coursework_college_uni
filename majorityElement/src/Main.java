import java.util.Hashtable;
import java.util.Set;

//MAJORITY ELEMENT SOLVED!!
public class Main {
    public static void main(String[] args)
    {
        //int[] arr = new int[] {2,2,1,1,1,2,2}; //majority = 2
        //int[] arr = new int[] {3, 2, 3}; //majority = 3
        //int[] arr = new int[] {3, 4, 5, 1, 5, 1, 5, 5, 5, 6, 99, 111}; //no majority using even number of elements
        //int[] arr = new int[] {3, 5, 5, 1, 5, 1, 5, 5, 5, 5, 99, 111}; //majority = 5, even # of elements
        //int[] arr = new int[] {3, 4, 5, 1, 5, 1, 5, 5, 5, 6, 99}; //no majority using odd number of elements
        int[] arr = new int[] {3, 4, 4, 1, 4, 1, 4, 4, 4, 6, 99}; //majority = 4, odd number of elements

        //System.out.print(arr.length);
        int majority = majorityElement(arr, 0, arr.length - 1);

        if (majority != -1) System.out.println("Majority element = " + majority);
        else System.out.println("No Majority");

    }

    public static int majorityElement(int[] nums, int startIndex, int endIndex)
    {
        if (startIndex == endIndex)
        {
            return startIndex;
        }
        //if (endIndex - startIndex + 1 == 1 || endIndex - startIndex + 1 == 2) return -1; //wrong
        int left;
        int right;
        int middle = (startIndex + endIndex) / 2;

        left = majorityElement(nums, startIndex, middle);
        right = majorityElement(nums, middle + 1, endIndex);

        //make dictionary for left and right half
        Hashtable<Integer, Integer> leftDict = new Hashtable<>();
        for (int i = 0; i <= middle; i++) //count the missing element at middle, need <=
        {
            if (leftDict.containsKey(nums[i]))
            {
                leftDict.replace(nums[i], leftDict.get(nums[i]), leftDict.get(nums[i]) + 1);
            }
            else
            {
                leftDict.put(nums[i], 1);
            }
        }

        Hashtable<Integer, Integer> rightDict = new Hashtable<>();
        //start at middle + 1, which is where the other half starts
        //end at endIndex + 1 (want to count the element at endIndex)
        for (int j = middle + 1; j < endIndex + 1; j++)
        {
            if (rightDict.containsKey(nums[j]))
            {
                rightDict.replace(nums[j], rightDict.get(nums[j]), rightDict.get(nums[j]) + 1);
            }
            else
            {
                rightDict.put(nums[j], 1);
            }
        }

        //merge frequencies of numbers from left and right half together into one dict
        //right dict will contain all the merged frequencies
        leftDict.forEach((k, v) -> rightDict.merge(k, v, (oldVal, newVal) -> oldVal + newVal));

        //find most frequent one, check if it is greater than n / 2, return number if majority else -1
        Set<Integer> s = rightDict.keySet(); //get the keys
        int mostFreq = -1;
        int keyToReturn = -1;
        for (Integer key : s) //go through each key
        {
            if (rightDict.get(key) > mostFreq) {
                mostFreq = rightDict.get(key);
                keyToReturn = key;
            }
        }

        if (mostFreq > nums.length / 2)
        {
            return keyToReturn;
        }
        else return -1;


    }
}

/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than floor(n / 2) times
Assume that the majority element always exists in the array.

Example:
Input: nums = [3,2,3]
Output: 3

Example:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

 */