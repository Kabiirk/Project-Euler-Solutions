/*
Problem 3
Euler discovered the remarkable quadratic formula:

n^2 + n + 41

It turns out that the formula will produce 40 primes
for the consecutive integer values 0 <= n <= 39 . However,
when n = 40, (40^2) + 40 + 41 = 40*(40+1) + 41 is divisible by 41,
and certainly when n = 41, (41^2) + 41 + 41 is clearly divisible by 41.

The incredible formula n^2 - (79*n) + 1601 was discovered, which produces 80 primes
for the consecutive values 0 <= n <= 79 . The product of the coefficients,
-79 and 1601, is -126479.

Considering quadratics of the form:

n^2 + a*n + b, where |a| < 1000 and |b| < 1000

where |n| is the modulus/absolute value of n
e.g.  |11| = 11 and |-4| = 4

Find the product of the coefficients, a and b, for the quadratic expression
that produces the maximum number of primes for consecutive values of n ,
starting with n = 0.

Answer : 
*/

/*
TIPS:

*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

void SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

int main()
{
	vec
    SieveOfEratosthenes(87400);
    
    return 0;
}
