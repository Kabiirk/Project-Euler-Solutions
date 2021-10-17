/*
Problem 57
It is possible to show that the square root of two can be expressed as an infinite continued fraction.
√ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...

By expanding this for the first four iterations, we get:
1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

The next three expansions are 99/70, 239/169, and 577/408,
but the eighth expansion, 1393/985, is the first example
where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator 
with more digits than denominator?

Answer : 
*/

/*
TIPS:
num = 3, 7, 17, 41, 99, 239, 577, 1393
--    -  -  --  --  --  ---  ---  ----
den = 2, 5, 12, 26, 70, 169, 408, 985
*/

#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long int ULL;

int numDigits(ULL n){
    int digits = 0;
    while(n > 0){
        n /= 10;
        digits++;
    }
    return digits;
}

int main() {
    int limit = 9;
    int res = 0;

    ULL den = 1;
    ULL num = 1;
    ULL num1, den1;

    for(int i = 1; i<limit; i++){
        num1 = num + 2*den;
        den1 = num + den;
        if(numDigits(num1) > numDigits(den1)){
            res++;
        }
        num = num1;
        den = den1;
        // cout<<"Numerator : "<<num_n_1<<" "<<numDigits(num_n_1)<<endl;
        // cout<<"Denminator : "<<den_n_1<<" "<<numDigits(den_n_1)<<endl;
    }

    cout<<res<<endl;

    return 0;
}
