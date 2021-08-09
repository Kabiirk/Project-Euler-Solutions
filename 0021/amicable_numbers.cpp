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
Brute Force :
Prime Factorisation :

*/

#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <map>

using namespace std;

// Brute Force approach & Helper functions
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

int bruteForce(int limit){
	int amicable_sum = 0;
	int sum_j, sum_k;
	for(int j = 0; j<limit; j++){
		
		sum_j = sumOfDivisors(j);
		
		if(sum_j>j && sum_j<=limit){
			
			sum_k = sumOfDivisors(sum_j);
			
			if(sum_k == j){			
				amicable_sum += j+sum_j;
			}
		}
	}
	return amicable_sum;
}


// Prime factorization approach & Helper functions
vector<int> SieveOfEratosthenes(int n)
{
	vector<int> prime_list;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p]){
            //cout << p << " ";
            prime_list.push_back(p);
    	}
            
    return prime_list;
}

int sumOfDivisorsPF(int num, vector<int> prime_list){
	int n = num;
	int sum = 1;
	int p = prime_list[0];
	int j;
	int i = 0;
	
	while (p * p <= n && n > 1 && i < prime_list.size()){
	    p = prime_list[i];
		i++;
		if (n % p == 0){
		    j = p * p;
			n = n / p;
			while (n % p == 0){
			    j = j * p;
			    n = n / p;
			}
		    sum = sum * (j - 1) / (p - 1);
		}
	}
	//A prime factor larger than the square root remains
	if (n > 1) {
        sum *= n + 1;
    }
    return sum - num;
}

int primeFactorization(int limit){
	int amicable_sum=0;
	int factors;
	vector<int> prime_list = SieveOfEratosthenes((int)sqrt(limit) + 1);
	map<int, int> dic;
	map<int,int>::iterator k;
	
	for(int i=2; i<=limit; i++){
		
		factors = sumOfDivisorsPF(i, prime_list);
		if(factors>i){
			dic.insert({ i, factors });
		}
		else if(factors<i){
			k = dic.find(factors);
			if(dic.find(factors)!=dic.end()){
				if((k->second)==i){	
					amicable_sum += i+factors;
				}
			}
		}
	}
	return amicable_sum;
}

int main()
{
	cout<<bruteForce(10000)<<endl;
	cout<<primeFactorization(10000)<<endl;

    return 0;
}
