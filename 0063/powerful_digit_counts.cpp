/*
Problem 63
The 5-digit number, 16807=7^5, is also a fifth power.
Similarly, the 9-digit number, 134217728=8^9, is a ninth power.

How many n-digit positive integers exist which are also an nth power?

Answer : 
*/

/*
TIPS:
say log10 => log base 10
i.e. log10(100) = 2
as 10^2 = 100


10^(n-1) <= x^n < 10^n

for n-digit no.
10(n-1) <= x^n is the lower bound

For Lower Bound
taking log10

=> n-1 = n*log10(x)
=> log10(x) = n-1/n
=> x = 10((n-1)/n)

For upper bound
limit(n -> infinity) (n-1)/n= 1
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int res=0,lower=0,n=1;

    while(lower<10){
        lower = (int)ceil(pow(10.0,(n-1.0)/n));
        res+=10-lower;
        n++;
    }
    cout<<res<<endl;

    return 0;
}
