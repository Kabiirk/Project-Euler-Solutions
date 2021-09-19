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

#include <iostream>
#include <vector>

using namespace std;

long long int ModifiedSieveOfEratosthenes(const int n)
{
    vector<bool> prime(n + 1, true);
 
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
	const int n = 2000000;
	long long int sum_of_primes = ModifiedSieveOfEratosthenes(n);
	cout<<sum_of_primes<<endl;
	
    return 0;
}
