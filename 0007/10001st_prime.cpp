/*
Problem 7
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

Answer : 104743
*/

/*
TIPS :
Find the prime numbers up to MAX_SIZE using Sieve of Eratosthenes.

Store all primes in a vector.

For a given number N, return the element at (N-1)th index in a vector.
*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_SIZE 1000005

void Sieve_of_Eratosthenes(vector<long long int>& primes){
	
	bool IsPrime[MAX_SIZE];
	memset(IsPrime, true, sizeof(IsPrime));
	
	for(int p = 2; p*p<MAX_SIZE; p++){
		if(IsPrime[p] == true){
			for(int i = p*p; i<MAX_SIZE; i+=p){
				IsPrime[i] = false;
			}
		}
	}
	
	for(int p = 2; p<MAX_SIZE; p++){
		if(IsPrime[p]){
			primes.push_back(p);
		}
	}
	
}

int main(){
	vector<long long int> primes;
	int n = 10001;
	
	Sieve_of_Eratosthenes(primes);
	
	cout<<primes[n-1]<<endl;

	return 0;
}
