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
#include <cmath>

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
    int max_digit_sum = 0;
    int a_max, b_max;
    int num= 0;
    for(int a = 2; a<=8; a++){
        for(int b = 2; b<=8; b++){
            int power_num = pow(a, b);
            int current_digit_sum = digitSum(power_num);
            cout<<a<<"^"<<b<<" = "<<power_num<<" -> "<<current_digit_sum<<endl;
            if(current_digit_sum > max_digit_sum){
                max_digit_sum = current_digit_sum;
                a_max = a;
                b_max = b;
                num = power_num;
            }
        }
    }
    cout<<max_digit_sum<<" "<<a_max<<" "<<b_max<<" "<<num<<endl;

    return 0;
}
