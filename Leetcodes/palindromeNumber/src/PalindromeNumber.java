//submitted 10/22/2026, accepted. Similar to my Main.java when
//I did it in my IDE where I passed an Integer type instead of a normal int.
//logic is basically the same, but negative number check 
//and string conversion is done in the function in this file instead of Main.

class Solution {
    public boolean isPalindrome(int x) {
        
        if (x < 0) return false; //negative number can't be a palindrome at all.
        
        //use Integer class to use the method to convert to a string
        Integer num = Integer.valueOf(x);
        String s = num.toString();

        int startPointer = 0;
        int endPointer = s.length() - 1;

        //S[i] and S[length - 1], S[i + 1] and S[length - 2], etc, should be the same

        while (startPointer < endPointer)
        {
            if (s.charAt(startPointer) != s.charAt(endPointer))
                return false;
            
            startPointer++;
            endPointer--;
        }

        return true;
    }
}
