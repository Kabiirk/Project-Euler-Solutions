/*
Problem 35
The number, 197, is called a circular prime because all
rotations of the digits: 197, 971, and 719, are themselves
prime.

There are thirteen such primes
below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?

Answer : 55
*/

/*
TIPS:
Generate all left shifts of number, check each if prime or not,
increment circular count by 1 if all rotations of a number are
primes.

Note : I initiall used Sieve of Eratosthenes to verify primes,
       but it wasn't working for higher numbers so i used 
       a simpler method.
*/

#include <iostream>
#include <vector>
#include <cstring> // for memset()
#include <cmath> // for pow()

using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

bool isCircularPrime(unsigned int num){
    // because multiples of 10 cause
    // an infinite loop during rotation
    if(num%10 == 0){
        return false;
    }

    bool circ_prime = true;
    unsigned int shift = 1;
    while (num > shift * 10)
      shift *= 10;

    auto rotated = num;
    do
    {
      // take right-most digit
      auto digit = rotated % 10;
      // remove it
      rotated /= 10;
      // and prepend it
      rotated += digit * shift;
      circ_prime = circ_prime && isPrime(rotated);

      // rotated number not prime ?
    //   if (primes.count(rotated) == 0)
    //     break;
    } while (rotated != num);

    return circ_prime;
}

int main()
{
    unsigned int limit = 1000000;
    //unsigned int arr[limit];
    unsigned int circular_primes_count = 0;

    for(unsigned int i=2; i<limit; i++){
        if(isCircularPrime(i)){
            circular_primes_count += 1;
        }
    }
    cout<<circular_primes_count<<endl;

    return 0;
}
