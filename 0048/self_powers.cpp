/*
Problem 48
The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

Answer : 9110846700
*/

/*
TIPS:
We will use Modular Arithmetic for this :
Ref.: https://en.wikipedia.org/wiki/Modular_arithmetic

The modulo operator or rather modular arithmetic has some pretty interesting
properties for this problem both on addition and multiplication.

The properties we want to exploit are

(a*b) % c = ((a % c) * (b % c) )% c

and

(a+b) % c = ((a % c) + (b % c) )% c.

Since we only need the last ten digits of the results these properties mean
that we can cut away all of the leading digits during our calculation (with %10000000000).

NOTE :
added : below code
----------------.
if(N%10==0)     |
{               |
    continue;   |
}               |
----------------.
because number of below form :
(k∗10)^(k∗10) = k^(k∗10) ∗ 10^(k∗10) = k^(k∗10) ∗ 10^k ∗ 10^10
won't contribute to the answer

TIPS : 
Ref.: https://codereview.stackexchange.com/questions/64565/calculating-the-last-digit-of-ab-where-a-and-b-are-very-large-numbers/64573#64573
(for calculating large powers(a^b) with complexity O(1))

*/

#include <iostream>

using namespace std;
#define mod 10000000000

int main()
{
    long long result = 0;

    for(int i = 1; i<=1000; i++){
        if(i%10==0){
            continue;
        }
        long long base = i;
        for(int j = 1; j<i; j++){
            base*=i;
            base %= mod; // so that only the last 10 digits remain
        }

        result += base;
        result %= mod;
    }

    cout<<result<<endl;

    return 0;
}
