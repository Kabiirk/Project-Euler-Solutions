/*
Problem 5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Answer : 232792560
*/

/*
TIPS :
In a way, we have to find a number which is
the LCM(Lowest Common Multiple) of all numbers between 1-20
for it to be divisble by all of them and, it would be the smallest number
by definition of LCM.

now
LCM(a,b) = (a*b)/GCD(a,b)

but 
LCM(a,b,c) != (a*b*c)/GCD(a,b,c)

Iterate over all the elements of the array i.e. from i = 1 to i = n-1 
At the ith iteration ans = LCM(arr[0], arr[1], ..., arr[i-1]). 
This can be done easily as LCM(arr[0], arr[1], ..., arr[i]) = LCM(ans, arr[i]).
Thus at 'i'th iteration we just have to do ans = LCM(ans, arr[i]) = ans x arr[i] / gcd(ans, arr[i]) 
*/

#include<iostream>

using namespace std;

int gcd(int a, int b){
	if(b==0){
		return a;
	}
	return gcd(b, a%b);
}

long long int findlcm(int arr[], int n){
	long long int ans = arr[0];
	
	for(int i=1; i<n; i++){
		ans = (((arr[i]*ans))/(gcd(arr[i], ans)));
	}
	return ans;
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<findlcm(arr, n)<<endl;

	return 0;
}
