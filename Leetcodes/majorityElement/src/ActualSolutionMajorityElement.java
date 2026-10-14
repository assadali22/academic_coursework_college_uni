//Accepted on Leetcode on 10/14/2026, 4:50PM. Very odd that my initial divide and conquer solution had a timeout erorr..
//Simply just go through the whole array, count the frequency of each number with a hash table
//then go through each key and see which one has the larger frequency.

import java.util.Hashtable;
import java.util.Set;

class Solution {
    public int majorityElement(int[] nums) {
        Hashtable<Integer, Integer> freq = new Hashtable<>(); //key is the number, value is the frequency

        //pass through the array and count the frequency of each number
        for (int i = 0; i < nums.length; i++)
        {
            if (freq.containsKey(nums[i]))
                freq.replace(nums[i], freq.get(nums[i]), freq.get(nums[i]) + 1); //increment frequency by 1 if the number already exists
            else
                freq.put(nums[i], 1);
        }

        Set<Integer> s = freq.keySet(); //get the keys
        int mostFreq = -1;
        int keyToReturn = -1;
        for (Integer key : s)
        {
            if (freq.get(key) > mostFreq)
            {
                mostFreq = freq.get(key); //update which element had the highest frequency
                keyToReturn = key;
            }
        }

        return keyToReturn;
    }

    
}
