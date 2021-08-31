/*
Problem 36
Problem 37
The number 3797 has an interesting property. Being prime itself, 
it is possible to continuously remove digits from left to right,
and remain prime at each stage: 3797, 797, 97, and 7.
Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable
from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

Answer : 748317
*/

/*
TIPS:
Create a sieve of primes uptill 1000000 (not bect practice due to stack issues)
for each prime in that list check for left & right truncated primes then add accordingly

Right truncation : 
num/10 -> removes last digit
e.g. :
3797/10 = 379 (C++ outputs floor int value)
379/10 = 37
37/10 = 3

Left truncation :
a little tricker than right truncation
we first need to find highest power of 10 grater than the number
factor can be divided by 10 to reduce an extra step of checking original number for being a prime
factor%num -> removes left-most digit
factor/10 to scale down the factor since our left most digit is reduced, otherwise we will get the same answer on repeat
e.g. :
highest power of 10 greater than 3797 = 10000
3797%10000 = 3797 (can be avoided by dividing factor by 10 first)
3797%1000 = 797
797%100 = 97
97%10 = 7
(also notice how factor is divided by 10 in each step so that we arent stuck on an answers)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieveEro(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

bool allRightTruncatePrimes(int n, vector<bool> prime_list){
    bool final = true;
    while(n>10){
        n = n/10;
        final = final && prime_list[n];
        //cout<<n<<","<<final<<">";
    }
    return final;
}

// helper function for allLeftTruncatePrimes
int largestPowerTen(int n){
    int factor = 1;
    while(factor<n){
        factor*=10;
    }
    return factor;
}

bool allLeftTruncatePrimes(int n, vector<bool> prime_list){
    bool final = true;
    int factor = largestPowerTen(n)/10;
    while(n>10){
        n = n%factor;
        final = final && prime_list[n];
        //cout<<n<<","<<final<<">";
        factor = factor/10;
    }
    return final;
}

int main()
{
    vector<bool> a = sieveEro(1000000); // find a better way to do this, usuallynot a good practice to create a vector having a million values
    int truncatable_prime_count=0;
    int truncatable_prime_sum=0;
    int i = 10;

    while(11 > truncatable_prime_count){
        if(a[i]){
            if(allRightTruncatePrimes(i,a) && allLeftTruncatePrimes(i,a)){
                //cout<<i<<endl;
                truncatable_prime_count += 1;
                truncatable_prime_sum += i;
            }
        }
        i = i+1;
    }

    cout<<truncatable_prime_sum<<endl;

    return 0;
}
