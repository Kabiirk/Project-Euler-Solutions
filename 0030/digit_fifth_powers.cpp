/*
Problem 30
Surprisingly there are only three numbers that can be written
as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as
the sum of fifth powers of their digits.

Answer : 443839
*/

/*
TIPS:
1) Brute Force : for each valid digit. We first need to calculate the
'Upper-bound' of our problem i.e. till what number n is
sum of n's digits^5 is equal to n itself.

The sum of the digits' fifth powers is maximized when each digit is 9:
1 digit:  9^5 = 59049
2 digits:  9^5 = 118098
3 digits:  9^5 = 177147
4 digits:  9^5 = 236196
5 digits:  9^5 = 295245
6 digits:  9^5 = 354294
7 digits:  9^5 = 413343

From this we notice that it's impossible for a seven-digit number to have
a seven-digit sum of its digits' fifth powers, because all those sums
would have at most six digits.

After that the code is just iterating through the numbers(i or current_num),
Breaking them into constituent digits and calculate sum of their
digits' 5th power(current_sum).

if current_sum is equal to our number, we add it to our final value

Some refferences to alternative approaches :
1) https://stackoverflow.com/questions/10286999/number-equal-to-the-sum-of-powers-of-its-digits
2) https://math.stackexchange.com/questions/136168/number-equal-to-the-sum-of-powers-of-its-digits
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned int exponent = 5;
    unsigned int sum = 0;

    for(unsigned int i = 2; i<7*pow(9,5); i++){
        unsigned int current_sum = 0;
        unsigned int current_num = i;

        // Splitting number into digits
        while(current_num>0){
            // get the digit
            unsigned int digit = current_num % 10;
            // remove digit from current_num
            current_num /= 10;

            unsigned int digit_fifth_power = pow(digit, 5);
            current_sum += digit_fifth_power;
        }

        if(current_sum == i){
            //cout<<i<<endl;
            sum+= i;
        }
    }

    cout<<sum<<endl;
    
    return 0;
}
