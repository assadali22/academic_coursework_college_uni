/*
Chapter 8 Programming Exercises Problem 21

A positive integer n is called prime if n > 1 and the only factors of n
are 1 and n. It is known that a positive integer n > 1 is prime if n is not
divisible by any prime integer m <= sqrt(n). The 1230th prime number is
10,007. Let t be an integer such that 2 <= t <= 100,000,000.
Then t is prime if either t is equal to one of the first 1,230 prime
numbers or t is not divisible by any of the first 1,230 prime numbers.
Write a program that declares an array of size 1,230 and stores the
first 1,230 prime numbers in this array. The program then uses the
first 1,230 prime numbers to determine if a number between 2 and 100,000,000 is prime. If a number
is not prime, then output at least one of its prime factors.
*/


#include <iostream>
using namespace std;
const int PRIME_SIZE = 1230;
//Function Prototype
void storePrime(int primeArr[], int S);
bool findPrime(int j);
bool isTPrime(int primeArr[], int S, int t);

int main()
{
    int primeArr[PRIME_SIZE] = {1};
    int t = 0;
    bool tPrime = 0;

    storePrime(primeArr, PRIME_SIZE);
    cout << "Enter an integer, t, between 2 and 100,000,000 inclusive: ";
    cin >> t;

    tPrime = isTPrime(primeArr, PRIME_SIZE, t);

    if (tPrime)
    {
         cout << t << " is a prime number." << endl;
    }
    else
    {
        cout << t << " is NOT prime." << endl;
    }

    cout << "1230th prime number = " << primeArr[1229] << endl;
    return 0;
}


void storePrime(int primeArr[], int S)
{
    int i = 0;
    int j = 2;
    bool prime;
    for (i = 0; i < S;)
    {

        prime = findPrime(j);

        if (prime)
        {
            primeArr[i] = j;
            i++;
        }
        j++;
    }
}


bool findPrime(int j)
{
    int primeStart = 0;
    int remainder = 0;
    int flag = 1;

    for (primeStart = 2; primeStart <= j - 1; primeStart++)
    {
        remainder = j % primeStart;
        if (remainder == 0)
        {
            primeStart = j;
            flag = 0;
        }
    }

    if (flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool isTPrime(int primeArr[], int S, int t)
{
    int i = 0;
    for (i = 0; i < S; i++)
    {
        if (t == primeArr[i])
        {
            return true;
        }
        else if (t % primeArr[i] == 0)
        {
            return false;
        }

    }
    return true;
}

/*
Sample Run 1
Enter an integer, t, between 2 and 100,000,000 inclusive: 9883
9883 is a prime number.
1230th prime number = 10007

Sample Run 2
Enter an integer, t, between 2 and 100,000,000 inclusive: 148971
148971 is NOT prime.
1230th prime number = 10007

Sample Run 3
Enter an integer, t, between 2 and 100,000,000 inclusive: 9814419
9814419 is NOT prime.
1230th prime number = 10007

Sample Run 4
Enter an integer, t, between 2 and 100,000,000 inclusive: 2000003
2000003 is a prime number.
1230th prime number = 10007

Sample Run 5
Enter an integer, t, between 2 and 100,000,000 inclusive: 956577
956577 is NOT prime.
1230th prime number = 10007


*/
