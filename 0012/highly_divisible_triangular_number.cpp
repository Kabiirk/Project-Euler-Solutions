/*
Problem 12
The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

 1: 1
 3: 1,3
 6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28
We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?

Answer : 
*/

/*
TIPS:
                                                     .
                                             .       ..
                                      .      ..      ...
                                .     ..     ...     ....
triangle representation    .    ..    ...    ....    .....    and so on ........

      triangular number    1    3     6      10      15       and so on ........
                          ----------------------------------
     sum representation    1    1     1      1       1
                               +2     2      2       2
                                     +3      3       3
                                            +4       4
                                                    +5
                          
looking at the series, the nth Triangular number is:
1+2+3+4+.....+n = (n*(n+1))/2
[sum of n natural numbers]

A naive solution: To iterate for every triangular number and count the 
number of divisors using the Sieve method. At any moment if the number of 
divisors exceeds the given number N, then we get our answer. If the triangular 
number which has more than N divisors is X, then the time complexity will 
be O(X * sqrt(X)) as pre-processing of primes is not possible in case of 
larger triangular numbers.

An efficient solution : To use the fact that the triangular number�s 
formula is x*(x+1)/2. The property that we will use is that k and k+1 are 
coprimes. We know that two co-primes have a distinct set of prime factors.
There will be two cases when X is even and odd. 
 

When X is even, then X/2 and (X+1) will be considered as two numbers whose prime factorisation is to be find out.
When X is odd, then X and (X+1)/2 will be considered as two numbers whose prime factorisation is to be find out.
Hence the problem has been reduced to the just finding out prime factorization of smaller numbers, which reduces
*/

#include <bits/stdc++.h>

const int MAX = 100000;

using namespace std;

int main()
{
    
    
    return 0;
}
