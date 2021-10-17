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

Answer : 153
*/

/*
TIPS:
num = 3, 7, 17, 41, 99, 239, 577, 1393
--    -  -  --  --  --  ---  ---  ----
den = 2, 5, 12, 26, 70, 169, 408, 985

from this we notice the general formula for nth
numerator & denominator as :

num(n+1) = num(n) + 2*den(n)
den(n+1) =  num(n) + den(n)

We reach the same formula via solving as fractions;
Ref. : https://euler.stephan-brumme.com/57/

Same formula + pen-paper approach
Ref. : https://www.mathblog.dk/project-euler-57-square-root-two/
*/

#include <iostream>
#include <vector>
// #include <algorithm> // for transform()

using namespace std;

typedef vector<int> bignum;

bignum addVect(const bignum a, const bignum b){
    bignum sum = b;

    int carry = 0;
    for(int i = 0; i < sum.size(); i++){
        if(i<a.size()){
            sum[i] += a[i];
        }
        sum[i] += carry;
        
        // handle overflow
        if(sum[i] >= 10){
            carry = 1;
            sum[i] -= 10;
        }
        else{
            carry = 0;
        }
    }

    // If Largest Digit overflowing
    if(carry != 0){
        sum.push_back(carry);
    }

    return sum;
}

bignum scalarMultipleVect(bignum vect, int scalar){
    // Ref. : https://stackoverflow.com/questions/3885095/multiply-vector-elements-by-a-scalar-value-using-stl
    // Ref. : https://stackoverflow.com/questions/41030911/how-to-multiply-a-vector-and-scalar-in-c
    // return transform(vect.begin(), vect.end(), vect.begin(), bind(multiplies<unsigned int>(), placeholders::_1, scalar));

    int n = vect.size();
    int carry= 0;
    for(int i = 0; i<n; i++){
        vect[i] *= 2;
    }
    return vect;
}

// ease of debugging
void printVector(bignum vect){
    cout<<"< ";
    for (unsigned int i: vect){
        std::cout << i << ' ';
    }
    cout<<">"<<endl;
}

int main() {
    int limit = 1000;
    int res = 0;

    bignum numer = {1};
    bignum denom = {1};
    bignum numer1, denom1;
    for(int i = 1; i<limit; i++){
        numer1 = addVect(numer,scalarMultipleVect(denom, 2));
        denom1 = addVect(denom, numer);
        if(numer1.size() > denom1.size()){
            res++;
        }
        numer = numer1;
        denom = denom1;
    }

    cout<<res<<endl;

    bignum a = {1,2,3,4};
    bignum b = {1,2,3,4, 5};
    printVector(addVect(a, b));

    // Ref.: https://stackoverflow.com/questions/28607912/sum-values-of-2-vectors
    // transform (a.begin(), a.end(), b.begin(), a.begin(), plus<int>());
    // printVector(a);

    return 0;
}
