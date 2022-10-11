// Mersenne-Germain-Primes.cpp 
/*
A prime number p is a Mersenne prime if (2^p - 1) is also prime.
for example p=11 is not a Mersenne number because 2^11 - 1 = 2047
which is divisible by 23 and 89. However, p=3 is a Mersenne prime
because (2^3-1)=7 which is also a prime number.

A prime p is a Germain prime if (2p + 1) is also prime. For instance,
p=7 is not Germain because (2*7 + 1)=15 which is divisible by 3 and 5.
However, p=11 is Germaine, observe that (2*11 + 1)=23, and 23 is prime.
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int N = 10;

bool isPrime(long n);
bool isMersenne(long p);
bool isGermain(long p);
// ----------------------------------------------------------------------
int main()
{
    int mCounter = 0;
    long candidate = 2;

    cout << left << setw(5) << "p" 
        << left << setw(15) << "Mersenne(p)" 
        << left << setw(15) << "Germain(p)" 
        << left << setw(15) << "Is Mersenne?" 
        << left << setw(15) << "Is Germain?" << endl;

    //Explore a few candidate numbers
    while (mCounter < N)
    {
        if (isPrime(candidate) )
        {
            cout << setw(5) << left << candidate
                << setw(15) << left << pow(2, candidate) - 1
                << setw(15) << left << 2 * candidate + 1
                << setw(15) << left << (isMersenne(candidate) ? "T" : "F")
                << setw(15) << left << (isGermain(candidate) ?  "T" : "F")
                << endl;
            mCounter++;
        }
        candidate++;
    }
}

//-----------------------------------------------------------------------
bool isPrime(long p)
{
    if (p == 0 || p == 1) return false;
    for (int i = 2; i <= p / 2; i++)
    {
        if (p % i == 0) return false;
    }
    return true;
}

bool isMersenne(long p)
{
    //assuming p is prime
    long mp = pow(2, p) - 1;
    return isPrime(mp);
}

bool isGermain(long p)
{
    //assuming p is prime
    long mp = 2*p + 1;
    return isPrime(mp);
}