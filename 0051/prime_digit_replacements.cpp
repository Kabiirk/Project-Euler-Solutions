/*
Problem 51
By replacing the 1st digit of the 2-digit number *3,
it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with
the same digit, this 5-digit number is the first
example having seven primes among the ten generated
numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
Consequently 56003, being the first member of this family, 
is the smallest prime with this property.

Find the smallest prime which, by replacing part of
the number (not necessarily adjacent digits) with
the same digit, is part of an eight prime value family.

Answer : 
*/

/*
TIPS:
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> prime_num;

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

    for(int j = 2; j<=n; j++){
        if(prime[j]){
            prime_num.push_back(j);
        }
    }

    return prime;
}

int main()
{
    int limit = 1000000;
    vector<bool> prime_bool = sieveOfEratosthenes(limit);

    return 0;
}
