/*
Problem 20
n! means n * (n - 1) * ... * 3 * 2 * 1

For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

Answer : 648
*/

/*
TIPS:
We calculate factorial normally, but
instead of using int/long/long long int to hold our number
We use an array where each index hold one digit of the number
after multiplication.
e.g. say our initial array 'A' holds value 1 :
[1, 0, 0, ...]

A*2 will be :
[2, 0, 0, ...]

similarly now A*7 (using current value A holds in previous step) :
[4, 1, 0 ...] 
(it should be 14, but digits are stored in reverse,
makes it easier to accomodate the carry.)

now A*8 becomes :
[2, 1, 1 ...]

NOTE :
Here a pre-defined array of size 500 was used (to hold numbers 500 digits long)
but it is a little hard-coded , instead, a vector could be used and carry could
be added with the push_back() method accordingly.

Another thing to keep in mind is that while multiplying, unlike adding,
carry-over value can be >1, or very large.
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 500
 
int multiply(int x, int res[], int res_size);
 
// This function finds factorial of large numbers
int factorialSum(int n)
{
    int res[MAX];
 
    // Initialize result
    res[0] = 1;
    int res_size = 1;
 
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);

    int sum = 0;
    for (int i=res_size-1; i>=0; i--)
    	sum+=res[i];
        //cout << res[i];
    // returns sum of digits by iterating over the array
    return sum;
}
 
int multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry
 
    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
 
        // Store last digit of 'prod' in res[] 
        res[i] = prod % 10; 
 
        // Put rest in carry
        carry  = prod/10;   
    }
 
    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

int main()
{
	
	cout<<factorialSum(100)<<endl;
    
    return 0;
}
