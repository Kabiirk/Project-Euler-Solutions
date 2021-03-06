/*
Problem 3
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

Answer : 6857
*/

/*
TIPS:
Naive Approach : The approach is simple, just factorise the 
given number by dividing it with the divisor of a number and 
keep updating the maximum prime factor. Complexity : O(sqrt(n))

Better Alternative : Sieve of Eratosthenes. Complexity : O(n*log2*log2(n))

Even Better : Sieve of Atkin (slightly faster than Sieve of Eratosthenes)
*/

#include <vector>
#include <iostream>

using namespace std;

int SieveOfEratosthenes(int x,long long signed int n)
{
    //use sieve upto square root of 
    // required number
    vector<bool> prime(x, true);                                 
 
    for (long long signed int p = 2; p * p <= x; p++)    
    {
        if (prime[p] == true) 
        {
            for (long long signed int i = p * p; i <= x; i += p)
                prime[i] = false;
        }
    }
    int res;
    for (long long signed int p = 2; p <= x; p++)
        if (prime[p])
            {
                if(n%p==0)   //if number is divisble by prime number than update with 
                res=p;        //latest value of prime number
            }
            return res;
}

int main()
{
    // for competitiva coding
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // 775146 is sqrt of 600851475143
    int res = SieveOfEratosthenes(775146,600851475143);

    cout<<res<<endl;//Return the answer

    // long long signed int n;cin>>n;   for value of n
   //cout<<SieveOfEratosthenes(sqrt(n),n);
    return 0;
}
