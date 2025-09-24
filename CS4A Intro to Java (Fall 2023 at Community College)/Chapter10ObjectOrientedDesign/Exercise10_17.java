/*
(Square numbers)
Find the first ten square numbers that are greater than Long.MAX_VALUE. A square number is a number in the form of n^2. For example, 4, 9, and 16 are square numbers. Find an efficient approach to run your program fast.
Sample Run
The ten numbers are
9223372037000250000
9223372043074251001
9223372049148252004
9223372055222253009
9223372061296254016
9223372067370255025
9223372073444256036
9223372079518257049
9223372085592258064
9223372091666259081
*/

import java.math.BigInteger;
public class Exercise10_17
{
    public static void main(String[] args)
    {
         BigInteger max = new BigInteger(Long.MAX_VALUE + "");
         BigInteger one = new BigInteger("1");
         BigInteger n = new BigInteger(max.sqrt() + "");


         System.out.println("The ten numbers are");
         int count = 0;
         while (count < 10)
         {
             BigInteger product = new BigInteger(n.multiply(n) + "");
             if (product.compareTo(max) == 1)
             {
                 System.out.println(product);
                 count++;
             }

             n = n.add(one); //increment
         }

    }
}
