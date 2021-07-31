/*
The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

Answer : 837799
*/

/*
TIPS:
Brute Force approach works fine
But can be sped up further with Caching & Memoization
at the cost of higher memory usage.
(we can Cache existing chain paths)
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int CollatzChainLength(unsigned int n){
	int counter = 1; // the starting number is also a part of the chain
	while(n != 1){
		n = (int(n%2==0)*n/2) + (int(n%2!=0)*((3*n)+1));
		counter+=1;
	}
	return counter;
}

int main()
{
	unsigned int n = 1000000;
	int max_chain_len = 0;
	int max_chain_num = 0;
	
    while(n>0){
    	int current_chain_len = CollatzChainLength(n);
    	if(current_chain_len > max_chain_len){
    		max_chain_len = current_chain_len;
    		max_chain_num = n;
		}
		n-=1;
	}
    cout<<max_chain_len<< " " <<max_chain_num<<endl;
    
    return 0;
}
