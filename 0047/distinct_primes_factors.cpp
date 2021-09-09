/*
Problem 47
The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2^2 × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors
each. What is the first of these numbers?

Answer : 134043
*/

/*
TIPS:
Brute force solution, prime_list helps check wether factor is prime of not
we iterate and find count of distinct prime factors for numbers until our
criteria is met.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> prime_list;

vector<bool> sieveOfEratosthenes(int n)
{
    vector<bool> prime(n, true);
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    return prime;
}

int numDistinctPrimeFactors(long n){
    int counter = 0;
    long product = 1;
    if(prime_list[n]){
        return 1;
    }

    for(int i = 2; i<=n/2; i++){
        if(product*i > n){
            break;
        }
        if(n%i==0 && prime_list[i]){
            product*=i;
            counter++;
        }
    }

    return counter;
}

int main()
{
    prime_list = sieveOfEratosthenes(1000000);
    long prime_factor_count = 4; // As per question
    int flag;

    for(int i = 2; ; i++){
        flag = 1;
        for(int j = 0; j<prime_factor_count; j++){
            if( !(prime_factor_count == numDistinctPrimeFactors(i+j)) ){
                flag = 0;
                break;
            }
        }

        if(flag){
            cout<<i<<endl;
            break;
        }
    }
    

    return 0;
}
