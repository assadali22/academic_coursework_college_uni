/*
Ch.5 Programming Exercises Problem 13

Suppose that the first number of a sequence is x, where x is an integer.
a0 = x, a(n+1) = a(n) / 2 if a(n) is even
a(n+1) = 3 * a(n) + 1 if a(n) is odd.

Write a program that prompts the user to input the value of x.
The program outputs the integer k such that a(k) = 1 and the numbers
a0, a1, ... a(k)
For example, if x = 75, then k = 14, the numbers are
75, 226, 113, 340, 170, 85, 256, 128, 64, 32, 16, 8, 4, 2, 1.
*/

#include <iostream>
using namespace std;
int main()
{
    int x;
    int k = 0;

    cout << "Enter x: ";
    cin >> x;

    cout << x << " ";

    while (x != 1)
    {
        if (x % 2 == 0)
        {
            x = x / 2;
            cout << x << " ";
        }
        else
        {
            x = (x * 3) + 1;
            cout << x << " ";
        }
        k++;
    }
    cout << endl;
    cout << "The value of k where a(k) = 1 is " << k << endl;
    return 0;
}

/*
Sample Run 1
Enter x: 75
75 226 113 340 170 85 256 128 64 32 16 8 4 2 1
The value of k where a(k) = 1 is 14


Sample Run 2
Enter x: 111
111 334 167 502 251 754 377 1132 566 283 850 425 1276 638 319 958
479 1438 719 2158 1079 3238 1619 4858 2429 7288 3644 1822 911 2734
1367 4102 2051 6154 3077 9232 4616 2308 1154 577 1732 866 433 1300
650 325 976 488 244 122 61 184 92 46 23 70 35 106 53 160 80 40 20
10 5 16 8 4 2 1
The value of k where a(k) = 1 is 69


Sample Run 3
Enter x: 678
678 339 1018 509 1528 764 382 191 574 287 862 431 1294 647 1942 971
2914 1457 4372 2186 1093 3280 1640 820 410 205 616 308 154 77 232
116 58 29 88 44 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
The value of k where a(k) = 1 is 51


Sample Run 4 (condensed for simplicity)
Enter x: 732
732 366 183 550 275 826 413 1240 620 310 155 466 233 700 350 175 526
263 790 395 1186 593 1780 890 445 1336 668 334 167 ... 160 80 40 20 10 5 16 8 4 2 1
The value of k where a(k) = 1 is 95


Sample Run 5
Enter x: 873
873 2620 1310 655 1966 983 2950 1475 4426 2213 6640 3320 1660 830
415 1246 623 1870 935 2806 1403 4210 2105 6316 3158 ... 40 20 10 5 16 8 4 2 1
The value of k where a(k) = 1 is 147


Sample Run 6
Enter x: 2048
2048 1024 512 256 128 64 32 16 8 4 2 1
The value of k where a(k) = 1 is 11


Sample Run 7 (condensed)
Enter x: 65535
65535 196606 98303 294910 147455 442366 221183 663550
331775 995326 497663 1492990 746495 2239486 1119743 ...
3200 1600 800 400 200 100 50 25 76 38 19 58 29 88 44 22 11 34 17
52 26 13 40 20 10 5 16 8 4 2 1
The value of k where a(k) = 1 is 130
*/
