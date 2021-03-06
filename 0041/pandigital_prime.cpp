/*
Problem 41
We shall say that an n-digit number is pandigital if it makes
use of all the digits 1 to n exactly once.

For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

Answer : 7652413
*/

/*
TIPS:
Best optimization trick is to reduce solution space, then check wether
number is prime, then check for if it is Pan-digital.

Solution space can be greatly reduced by checking divisiblity by 3:

"A number is divisible by 3 if and only if the digit sum of the number is divisible by 3."

The digit sum is as the name implies the sum of the digits.
We can rather easily find the digit sum of pandigital
numbers since we know the digits.

Sum of 9 Digit Pan-digital numbers(any Permutation) -> 1+2+3+4+5+6+7+8+9 = 45 (Divisible by 3)
Sum of 8 Digit Pan-digital numbers(any Permutation) -> 1+2+3+4+5+6+7+8 = 36 (Divisible by 3)
Sum of 7 Digit Pan-digital numbers(any Permutation) -> 1+2+3+4+5+6+7 = 28 
Sum of 6 Digit Pan-digital numbers(any Permutation) -> 1+2+3+4+5+6 = 21 (Divisible by 3)
Sum of 5 Digit Pan-digital numbers(any Permutation) -> 1+2+3+4+5 = 15 (Divisible by 3)
Sum of 4 Digit Pan-digital numbers(any Permutation) -> 1+2+3+4 = 10 
Sum of 3 Digit Pan-digital numbers(any Permutation) -> 1+2+3 = 6 (Divisible by 3)
Sum of 2 Digit Pan-digital numbers(any Permutation) -> 1+2 = 3 (Divisible by 3)

From here it is pretty clear that all pandigital numbers except
4 and 7 digit ones are divisible by 3 and thus can’t be primes.

NOTE : Other option was using a list of primes generated by sieve
but That would mean generating primes till 987654321 but was taking a lot
of time. So isPrime() was used.
*/

#include <iostream>
#include <vector>

using namespace std;

bool isPrime(unsigned long int n){
    if(n<=1){
        return false;
    }
    if(n<=3){
        return true;
    }

    if(n%2 == 0 || n%3 == 0){
        return false;
    }

    for(unsigned long int i = 5; i*i <= n; i=i+6){
        if(n%i == 0 || n%(i+2) == 0){
            return false;
        }
    }

    return true;
}

bool isPandigital(unsigned long int n) {
    int digits = 0;
    int count = 0;
    int tmp;
 
    while (n > 0) {
        tmp = digits;
        digits = digits | 1 << (unsigned long int)((n % 10) - 1);
        if (tmp == digits) {
            return false;
        }
 
        count++;
        n /= 10;
    }
    return digits == (1 << count) - 1;
}

int main()
{
    unsigned long int max_pan_prime = 0;

    for(unsigned long int i = 1234; i<=7654321; i++){
        if(isPrime(i)){
            if(isPandigital(i)){
                if(i>max_pan_prime){
                    max_pan_prime = i;
                }
            }
        }
    }

    cout<<max_pan_prime<<endl;
    return 0;
}
