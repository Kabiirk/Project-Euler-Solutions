/*
Problem 6
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2 + 7^2 + 8^2 + 9^2 + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10)^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is .
3025 - 385 = 2640
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

Answer : 25164150
*/

/*
TIPS:
first we calculate sum of 'n' natural numbers using Gauss' Formula
& then square it(as per question requirement) (O(1) complexity)
S1 = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
S1 = (n(n+1))/2

Then We use a method similar to above formula for sum of 'n^2'
natural numbers (O(1) complexity)
S2 = 1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2 + 7^2 + 8^2 + 9^2 + 10^2
S2 = (n(n+1)(2n+1)) / 6

as per question to get our answer, we do :
(S1)^2 - S2 = answer
*/

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 100;
	long long int sum_of_n = (n*(n+1))/2;
	long long int sum_of_n_square = (n*(n+1)*((2*n)+1))/6;
	long long int diff = (sum_of_n*sum_of_n) - sum_of_n_square;
	
	cout<<diff<<endl;
	
	return 0;
}
