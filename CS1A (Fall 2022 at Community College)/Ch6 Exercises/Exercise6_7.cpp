/*
Chapter 6 Programming Exercises Problem 7

Write a program that prompts the user to enter two positive integers
less than 1,000,000,000 and the program outputs the sum of all the
prime numbers between the two integers. Two prime numbers are
called twin primes, if the difference between the two primes is 2
or -2. Have the program output all the twin primes and the number of twin
primes between the two integers.
*/

#include <iostream>
using namespace std;

void cycleThroughRange(int n1, int n2, int& sumOfPrimes, int& numOfTwinPrimes);
bool findPrime(int i, int& sumOfPrimes);
void checkTwinPrime(int p, int& numTwinPrimes, int& sumOfPrimes);

int main()
{
    int num1 = 0;
    int num2 = 0;
    int sumOfPrimes = 0;
    int numOfTwinPrimes = 0;

    cout << "Enter num1: ";
    cin >> num1;

    cout << "Enter num2: ";
    cin >> num2;

    while (num1 > num2)
    {
        cout << "Num1 can't be greater than num2. Enter num1: ";
        cin >> num1;
    }

    cycleThroughRange(num1, num2, sumOfPrimes, numOfTwinPrimes);

    cout << "Sum of prime numbers: " << sumOfPrimes << endl;
    cout << "Total sets of twin primes: " << numOfTwinPrimes << endl;
    return 0;

}



void cycleThroughRange(int n1, int n2, int& sumOfPrimes, int& numOfTwinPrimes)
{
    int i;
    int prime1 = 0;
    int prime2 = 0;
    bool isPrime1;
    bool isPrime2;
    for (i = n1; i < n2; i = i + 2)
    {
        isPrime1 = false;
        isPrime2 = false;
        prime1 = i + 1;
        prime2 = i + 2;

        isPrime1 = findPrime(prime1, sumOfPrimes);
        isPrime2 = findPrime(prime2, sumOfPrimes);

        if (isPrime1)
        {
            sumOfPrimes = sumOfPrimes + prime1;
            checkTwinPrime(prime1, numOfTwinPrimes, sumOfPrimes);
        }

        if (isPrime2)
        {
            sumOfPrimes = sumOfPrimes + prime2;
            checkTwinPrime(prime2, numOfTwinPrimes, sumOfPrimes);
        }


    }
}


void checkTwinPrime(int p, int& numTwinPrimes, int& sumOfPrimes)
{
    if (findPrime(p + 2, sumOfPrimes))
    {
        cout << p << " and " << p + 2 << " are twin primes." << endl;
        numTwinPrimes++;
    }

}



bool findPrime(int j, int& sumOfPrimes)
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


/*
Sample Run 1
Enter num1: 20
Enter num2: 100
29 and 31 are twin primes.
41 and 43 are twin primes.
59 and 61 are twin primes.
71 and 73 are twin primes.
Sum of prime numbers: 983
Total sets of twin primes: 4


Sample Run 2
Enter num1: 100
Enter num2: 200
101 and 103 are twin primes.
107 and 109 are twin primes.
137 and 139 are twin primes.
149 and 151 are twin primes.
179 and 181 are twin primes.
191 and 193 are twin primes.
197 and 199 are twin primes.
Sum of prime numbers: 3167
Total sets of twin primes: 7

Sample Run 3
Enter num1: 50
Enter num2: 100
59 and 61 are twin primes.
71 and 73 are twin primes.
Sum of prime numbers: 732
Total sets of twin primes: 2
*/
