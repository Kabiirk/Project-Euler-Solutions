/*
Problem 58
Starting with 1 and spiralling anticlockwise in the following way,
a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom
right diagonal, but what is more interesting is that 8 out of the 13
numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square
spiral with side length 9 will be formed. If this process is continued,
what is the side length of the square spiral for which the ratio of
primes along both diagonals first falls below 10%?

Answer : 26241
*/

/*
TIPS:
Pattern to generate each diagonal from center is :
bottom_right = (9, 25, 49, 81, 121, ....)  = 4n^2 + 4*n + 1
top_left = (5, 17, 37, 65, 101, ....)      = 4n^2 + 1
top_right = (3, 13, 31, 57, 91, ....)      = 4n^2 - 2*n + 1
bottom_right = (7, 21, 43, 73, 111, ....)  = 4n^2 + 2*n + 1

now say :
all_diag_num => Total diagonal numbers
diag_primes => All primes on diagonal
n => Layer numbers

Condition 1 :
diag_primes / all_diag_num < 0.1 (less than 10%, as per question)

using transposition and taking 0.1 as 10/100 = 1/10  this implies :
10*diag_primes < all_diag_num

Condition 2 :
If we add all four new corners for every layer plus the
starting element in the middle, for every nth layer we have :
all_diag_num = 4n + 1

Now substituting values from Conditions 1 & 2, i.e. :
10*diag_primes < all_diag_num -----> (1)
all_diag_num = 4n + 1 -------------> (2)

we can say that the break condition is :
10*diag_primes < 4*n + 1

Side length of nth layer will always be 2*n + 1

We loop over odd numbers here since the final answer (the number of rows)
is computed directly from the index (the distance from center to outer row).
This must always be an odd number, which is the case for the expression 2*n+1
so our equations can further be simplified by taking m = 2n + 1 as :
4n^2 + 4*n + 1  = m^2
4n^2 + 1       = (m-1)*m + 1
4n^2 - 2*n + 1  = (m-2)*m + 2
4n^2 + 2*n + 1  = (m-3)*m + 3

Another interesting thing (also observable in number spiral)
is that bottom_right corner is always a square and therefore
can never be a prime number, so we can discard that for faster
operations. So now our working equations are;
(m-1)*m + 1
(m-2)*m + 2
(m-3)*m + 3

We are doing a very standard prime-check here with isPrime()

NOTE : I was initially using Sieve of Eratosthenes for primality check,
but that was giving problems with larger numbers. another fast way to
check for primes is the Miller-Rabin primality test which is used in this solution :
https://euler.stephan-brumme.com/58/

Some additional approaches :
Ulam's spiral : https://mathworld.wolfram.com/PrimeSpiral.html
*/

#include <iostream>
#include <vector>

using namespace std;

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;

    if (n % 2 == 0 || n % 3 == 0)
        return 0;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
  
    return 1;
}

int main() {
    int p = 0;
    for(int m = 3; ; m+=2){
        p+= isPrime( (m-1)*m + 1 );
        p+= isPrime( (m-2)*m +2 );
        p+= isPrime( (m-3)*m + 3 );
        if(10*p < 2*m-1){
            cout<<m<<endl;
            break;
        }
    }
    return 0;
}
