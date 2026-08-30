/*
Problem 2 Add Two Numbers (SOLVED!)
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Started 8/25/2026: 9:45am - 10am (Setup + testing printing a linked list)
8/26/2026: 9pm-9:45pm
8/27/2026: 5:25-6:10pm (implementation), 6:10pm-7pm (testing, debugged if statement)

Example 1 (PASSED)
2 -> 4 -> 3
5 -> 6 -> 4
____________
7 -> 0 -> 8

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2 (PASSED)
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

This is 9,999,999 + 9,999, which is 10,009,998. A new significant digit added, which is ten millions

Example 3 (my example I made up) (PASSED)
L1 = [2, 7, 9], L2 = [7, 9], result should be [9, 6, 0, 1]

2 -> 7 -> 9
7 -> 9
______________
9 -> 6 (carry of 1 here) -> 0 (a carry of 1 here) -> 1

972 + 97 = 1069

(tested the example with 0 + 0 and yes, it works. I set example 2 to be 9,999,999 + 9,999)

Example 4 (my example I made up) (PASSED)
L1 = [3, 1], L2 = [3], result should be [6, 1]
13 + 3 = 16
*/

class ListNode
{
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Main
{
    public static void main(String[] args) {

        //example 1 linked lists
        //ListNode ex1L1 = new ListNode(2, new ListNode(4, new ListNode(3, null)));
        //ListNode ex1L2 = new ListNode(5, new ListNode(6, new ListNode(4, null)));

        //example 2 linked lists
        //ListNode ex2L1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, null)))))));
        //ListNode ex2L2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, null))));

        //example 3 linked lists
        //ListNode ex3L1 = new ListNode(2, new ListNode(7, new ListNode(9, null)));
        //ListNode ex3L2 = new ListNode(7, new ListNode(9, null));

        //example 4 linked lists
        ListNode ex4L1 = new ListNode(3, new ListNode(1, null));
        ListNode ex4L2 = new ListNode(3, null);

        ListNode curr = ex4L1;
        System.out.println("Printing list node L1: ");
        while (curr != null)
        {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
        System.out.println();

        curr = ex4L2;
        System.out.println("Printing list node L2: ");
        while (curr != null)
        {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
        System.out.println();

        ListNode sum = findLinkedListSum(ex4L1, ex4L2);

        curr = sum;
        System.out.println("Printing sum: ");
        while (curr != null)
        {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }


    }

    public static ListNode findLinkedListSum(ListNode firstNum, ListNode secondNum)
    {
        return findSumWithCarry(firstNum, secondNum, 0);
    }

    //just make another function signature with a carry to do the recursion (much easier to make another function)
    //why did I think that I have to implement using only leetcode's function signature
    public static ListNode findSumWithCarry(ListNode L1, ListNode L2, int carry)
    {
        if (L1 == null && L2 == null && carry == 0)
        {
            return null; // base case: no more carry and both linked lists are processed.
        }

        // base case: carry still exists after linked lists are processed
        if (L1 == null && L2 == null && carry == 1)
        {
            return new ListNode(1, null);
        }

        int rawSum; // for the whole sum, ex 9 + 5 = 14
        int digitSum; // corresponding digit (ex. 9 + 5 gives 4 as the digit, 1 as the carry)

        //normal case where we can add two digits, normal addition like on paper.
        if (L1 != null && L2 != null)
        {
            rawSum = L1.val + L2.val + carry;

            if (rawSum > 9)
                carry = 1;
            else
                carry = 0;

            digitSum = rawSum % 10;

            return new ListNode(digitSum, findSumWithCarry(L1.next, L2.next, carry));
        }
        else if (L1 != null) //L2 has fewer digits (no need for && carry != 0. Just check if L1 still has digits)
        {
            rawSum = L1.val + carry;

            if (rawSum > 9)
                carry = 1;
            else
                carry = 0;

            digitSum = rawSum % 10;

            return new ListNode(digitSum, findSumWithCarry(L1.next, null, carry));
        }
        else if (L2 != null) //L1 has fewer digits (no need for && carry != 0. Just check if L2 still has digits to process)
        {
            rawSum = L2.val + carry;
            if (rawSum > 9)
                carry = 1;
            else
                carry = 0;

            digitSum = rawSum % 10;

            return new ListNode(digitSum, findSumWithCarry(null, L2.next, carry));

        }

        return null;

    }
}


/*
bad and unfinished logic from the first attempt

        int rawSum; // for the whole sum, ex 9 + 5 = 14
        int digitSum ; // corresponding digit (ex. 9 + 5 gives 4 as the digit, 1 as the carry)
        int carry = 0;

        //normal case: there are two digits to add
        while (L1.next != null && L2.next != null)
        {
            rawSum = L1.val + L2.val;
            if (rawSum >= 10)
            {
                carry = 1;
            }
            digitSum = rawSum % 10;

            //L1.next.val = L1.next.val + carry;
            return new ListNode(digitSum, findLinkedListSum(L1.next, L2.next));
        }


        //alternate case where number of digits aren't the same
        while (L1.next != null)
        {
            rawSum = L1.val;
        }

        while (L2.next != null)
        {

        }

        return null;

 */
