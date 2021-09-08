/*
Problem 46
It was proposed by Christian Goldbach that every odd composite number
can be written as the sum of a prime and twice a square.

9 = 7 + 2×1^2
15 = 7 + 2×2^2
21 = 3 + 2×3^2
25 = 7 + 2×3^2
27 = 19 + 2×2^2
33 = 31 + 2×1^2

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a
prime and twice a square?

Answer : 5777
*/

/*
TIPS:
Reverse goldbach :
33 = 31 + 2×1^2

This implies
sqrt((33 - 31)/2) = 2

To generalize :
sqrt( (number - nearest_prime)/2 ) should be an integer
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes;

void sieveOfEratosthenes(int n)
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

    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
}

bool isGoldbach(int n){
    double sq_test = sqrt(n/2);

    return sq_test == (int)sq_test;
}


int main()
{
    sieveOfEratosthenes(10000);
    int result = 1;
    bool is_goldbach = true;
 
    while(is_goldbach){
        result += 2;
     
        int j = 0;
        is_goldbach = false;
        while (result >= primes[j]) {
            if(isGoldbach(result-primes[j])){
                is_goldbach = true;
                break;
            }
            j++;
        }
    }

    cout<<result<<endl;
    
    return 0;
}
