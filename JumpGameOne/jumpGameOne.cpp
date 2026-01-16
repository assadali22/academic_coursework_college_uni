/*
Problem: SOLVED! (on my set of test cases at least, not sure if there is some weird cases that would yield inconsistent results)
You are given an integer array nums. You are initially positioned at
the array's first index, and each element in the array represents your
maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.


Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what.
Its maximum jump length is 0, which makes it impossible to reach
the last index.

(started 1/2/2026 10:40AM)
(ran first version 11:40AM, passed 2 example cases above + my sample ones at the bottom!!)
SOLVED! (on my set of test cases at least, not sure if there is some
weird cases that would yield inconsistent results)
Time taken: a little over an hour, not bad

*/

#include <iostream>
using namespace std;
int solveJumpGame(int* arr, int* memoTable, int index, int arrSize);


int main()
{
    int sizeInput = 1;
    cout << "Enter array size: ";
    cin >> sizeInput;
    cout << endl;

    int* nums = new int[sizeInput]; //{2, 3, 1, 1, 4}
    //int numsTwo[] = {3, 2, 1, 0, 4};

    for (int i = 0; i < sizeInput; i++)
    {
        cout << "Enter element #" << i << " for array: ";
        cin >> nums[i];
        cout << endl;
    }

    cout << "Array is [";
    for (int i = 0; i < sizeInput; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;


    //Memo table: starting from some index, can we reach the last index?
    //Goal: the first element in the memo table, which represents starting from the first index (index 0)
    //Initial value: last element is true (1), rest is -1
    int* memo = new int[sizeInput];
    for (int i = 0; i < sizeInput; i++)
    {
        memo[i] = -1;
    }
    memo[sizeInput - 1] = 1;

    int index = 0;
    int canReach = 0;
    canReach = solveJumpGame(nums, memo, index, sizeInput);

    if (canReach == 1)
    {
        cout << "Can reach last index starting from index 0." << endl;
    }
    else
    {
        cout << "Can NOT reach last index from index 0." << endl;
    }

    delete [] nums;
    delete [] memo;
    cout << "Dynamic arrays deallocated with delete" << endl;
    return 0;
}


int solveJumpGame(int* arr, int* memoTable, int index, int arrSize)
{
    //if solution exists, return value in memo
    if (memoTable[index] != -1)
    {
        return memoTable[index];
    }

    if (index == arrSize - 1)
        return 1; //we reached the last index

    //recursion
    int num = arr[index];

    if (num > 0) //can jump if number is greater than 0.
    {
        int counter = 1;
        //for example if our number is 2, want to recursive call on index + 1 and index + 2 as long as we are within array bounds
        while (counter <= num)
        {
            //dont go out of bounds
            if (counter + index <= arrSize)
            {
                int recursiveCall = solveJumpGame(arr, memoTable, index + counter, arrSize);
                if (recursiveCall == 1) //if we found a solution, update memo and return true (1)
                {
                    memoTable[index] = 1;
                    return 1;
                }
            }

            counter++;
        }

    }

    memoTable[index] = 0;
    return 0;


}


/*
My test cases:
[3, 2, 1, 4, 0, 4], expected result should be true. PASSED

[2, 1, 3, 2, 0, 1], expected result should be true. PASSED

[2, 5, 0, 0], expected result should be true. PASSED

[3, 4, 10, 1, 5, 1, 7, 1] expected result should be true. PASSED

[1, 5, 2, 0, 1, 3, 0, 6], expected result should be true. (step 1 then step 4 times, then step 2 times to reach last index)

[1, 4, 0, 0, 1, 0, 1, 6], expected result should be false. PASSED! it worked

[2, 0, 1], passed. [7, 0, 9] passed.

[0, 2, 3], expected result is false. passed, my code works
[1, 0, 2], expected result is false. passed, my code works

[1, 1, 2, 2, 0, 1, 1], expected result is true, reachable. want to jump 2 times from index 4.
PASSED! it worked.


[2, 3, 0, 4, 0, 1], should be true (step once, then step twice to reach 4). passed!
*/
