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

Answer : 
*/

/*
TIPS:

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
    vector<bool> a = sieveEro(100000);
    int limit = 1000;
    int truncatable_prime_count=0;
    int truncatable_prime_sum=0;
    int i = 10;
    int num = 3797;


    // if(1){
    //     cout<<allRightTruncatePrimes(num,a)<< endl;
    //     cout<< allLeftTruncatePrimes(num,a) <<endl;
    // }


    while(11 > truncatable_prime_count){
        if(a[i]){
            if(allRightTruncatePrimes(i,a) && allLeftTruncatePrimes(i,a)){
                cout<<i<<endl;
                truncatable_prime_count += 1;
            }
        }
        i = i+1;
    }

    return 0;
}
