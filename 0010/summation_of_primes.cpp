/*
Problem 10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

Answer : 142913828922
*/

/*
TIPS:
Here we use a modified Sieve of Eratosthenes where instead of outputting primes,
it outputs a single value which is their sum
*/

#include <bits/stdc++.h>
using namespace std;

long long int ModifiedSieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // return sum of all prime numbers till n
    long long int sum = 0;
    for (int p = 2; p <= n; p++)
        if (prime[p]){
        	//cout << p << " ";
        	sum+=p;
		}
	return sum;
}

int main()
{
	int n = 2000000;
	long long int sum_of_primes = ModifiedSieveOfEratosthenes(n);
	cout<<sum_of_primes<<endl;
	
    return 0;
}
