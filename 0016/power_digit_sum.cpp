/*
Problem 16
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

Answer : 
*/

/*
TIPS:

*/


#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int digitSum(int n){
	int sum = 0;
	while (n != 0){
		sum = sum + n % 10;
        n = n / 10;
    }
    
	return sum;
}

int main()
{
	vector<unsigned int> digits;
	digits.push_back(1);
	digits.push_back(2);
	digits.push_back(3);
	
	for (int i = 0; i < digits.size(); i++) {
            cout << i<<" : "<<digits[i] << "\n";
        }
	
    
    return 0;
}
