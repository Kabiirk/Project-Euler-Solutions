/*
Problem 3
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

Answer : 233168
*/

/*
TIPS:

Naive Approach : The approach is simple, just factorise the 
given number by dividing it with the divisor of a number and 
keep updating the maximum prime factor. Complexity : O(sqrt(n))
Better Alternative : Sieve of Eratosthenes. Complexity : O(n*log2*log2(n))
Even Better : Sieve of Atkin (slightly faster than Sieve of Eratosthenes)
*/

#include<iostream>
#include "bits/stdc++.h"
using namespace std;
 
#define MAXN   100001
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
 
// driver program for above function
int main(int argc, char const *argv[])
{
    // precalculating Smallest Prime Factor
    sieve();
    int x = 12246;
    cout << "prime factorization for " << x << " : ";
 
    // calling getFactorization function
    vector <int> p = getFactorization(x);
 
    for (int i=0; i<p.size(); i++)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}
