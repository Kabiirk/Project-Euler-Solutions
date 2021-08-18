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

#include <iostream>

using namespace std;

int main()
{
    cout<<"Hello Euler !!"<<endl;
    return 0;
}
