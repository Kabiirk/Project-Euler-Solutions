/*
Problem 16
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

Answer : 1366
*/

/*
TIPS:

*/


#include <iostream>
#include <cstring>

using namespace std;
 
const int MAXN = 1000;
 
int result[MAXN+1];
 
int power(int a, int n)
{
    int digits, j;
 
    memset(result, 0, sizeof(result));
 
    result[0] = a;
    digits = 1;
    for(int i=2; i<=n; i++) {
        int carry = 0;
 
        for(j=0; j<digits; j++)
            result[j] *= a;
 
        for(j=0; j<=digits; j++) {
            result[j] += carry;
            carry = result[j] / 10;
            result[j] %= 10;
        }
        digits = j;
    }
 
    return digits;
}
 
int main()
{
    int n=1000;
	int digits;

    digits = power(2, n);
    int sum = 0;
    for(int i=0; i<=digits; i++)
       sum += result[i];
    
	cout << sum << endl;

    return 0;
}

