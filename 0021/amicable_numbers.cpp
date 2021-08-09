/*
Problem 21
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ? b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

Answer : 31626
*/

/*
TIPS:

*/

#include <bits/stdc++.h>
using namespace std;


int sumOfDivisors(int n){
	int sum = 1;
	for(int i=2; i<sqrt(n); i++){
		if(n%i==0){
			sum+=i;
			// handle perfect squares
			if(n/i != i){
				sum += n/i;
			}
		}
	}
	return sum;
}

int main()
{
	int upper_limit = 10000;
	int amicable_sum = 0;
	int sum_j, sum_k;
	for(int j = 0; j<10000; j++){
		
		sum_j = sumOfDivisors(j);
		
		if(sum_j>j && sum_j<=upper_limit){
			
			sum_k = sumOfDivisors(sum_j);
			
			if(sum_k == j){			
				amicable_sum += j+sum_j;
			}
		}
	}
	cout<<amicable_sum<<endl;
	
    
    return 0;
}
