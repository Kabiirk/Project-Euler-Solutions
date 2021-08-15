/*
Problem 3
Euler discovered the remarkable quadratic formula:

n^2 + n + 41

It turns out that the formula will produce 40 primes
for the consecutive integer values 0 <= n <= 39 . However,
when n = 40, (40^2) + 40 + 41 = 40*(40+1) + 41 is divisible by 41,
and certainly when n = 41, (41^2) + 41 + 41 is clearly divisible by 41.

The incredible formula n^2 - (79*n) + 1601 was discovered, which produces 80 primes
for the consecutive values 0 <= n <= 79 . The product of the coefficients,
-79 and 1601, is -126479.

Considering quadratics of the form:

n^2 + a*n + b, where |a| < 1000 and |b| < 1000

where |n| is the modulus/absolute value of n
e.g.  |11| = 11 and |-4| = 4

Find the product of the coefficients, a and b, for the quadratic expression
that produces the maximum number of primes for consecutive values of n ,
starting with n = 0.

Answer : -59231
*/

/*
TIPS:
1) Brute force (done here), 0.539 seconds , fast enough

2) Shrinking solution space
The quadratic formula has to provide us with primes all
the way from n= 0. What that means is that at n = 0

n^2 + an + b  = b

And thus b has to be a prime. That limits b from 2001
possibilities to 336. Or a factor 6 reduction in size.

For n = 1 we have that

n^2 + an + b  = 1 + a + b

We know that all primes except for 2 are odd. That means
if 1 + a + b has to be odd, a has to be odd as well so
the formula to provide a prime for n = 1.  If b = 2,
then a has to be even.

That cuts the possibilities of a by 50%. So we have
limited the total solution space by around a factor 12.
ref : https://www.mathblog.dk/project-euler-27-quadratic-formula-primes-consecutive-values/
*/

#include <iostream>

using namespace std;

bool isPrime(int n){
	if(n<=1){
		return false;
	}
	
	for(int factor=2; factor*factor <= n; factor++){
		if(n%factor == 0){
			return false;
		}
	}
	
	return true;
}

int main(){
	int limit = 1000;
	
	int a_max = 0;
	int b_max = 0;
	unsigned int n_max = 0;
	
	for(int a = -limit; a <= +limit; a++){
		for(int b = -limit; b <= +limit; b++){
			unsigned int n = 0;
			while(isPrime(n*n + a*n + b)){
				n++;
			}
			
			if(n>n_max){
				a_max = a;
			    b_max = b;
			    n_max = n;
			}
		}
	}
	
	cout<<a_max*b_max<<endl;
	
	return 0;
}
