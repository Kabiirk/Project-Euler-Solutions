/*
Problem 56
A googol (10^100) is a massive number: one followed by one-hundred zeros;
100^100 is almost unimaginably large: one followed by two-hundred zeros.
Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, a^b, where a, b < 100, what is
the maximum digital sum?

Answer : 
*/

/*
TIPS:

*/

#include <iostream>

using namespace std;

int digitSum(int n){
    int temp = 0;
    while(n > 0){
        temp += n%10;
        n = n/10;
    }
    return temp;
}

int main() {
    cout<<"Hello Euler !!"<<endl;
    cout<<digitSum(12345)<<endl;

    return 0;
}
