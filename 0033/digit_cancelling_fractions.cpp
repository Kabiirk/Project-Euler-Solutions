/*
Problem 33
The fraction 49/98 is a curious fraction, as an inexperienced
mathematician in attempting to simplify it may incorrectly
believe that 49/98 = 4/8, which is correct, is obtained by
cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial
examples.

There are exactly four non-trivial examples of this type of
fraction, less than one in value, and containing two digits
in the numerator and denominator.

If the product of these four fractions is given in its lowest
common terms, find the value of the denominator.

Answer : 
*/

/*
TIPS:
2 digit fractions
i.e. (10->99)/(10->99)

fraction should be lesser than 1
i.e. numerator < denominator

1) Brute Force approach
   Try all possible fraction combinations with 2 digit numbers
   as numerator and denominator, based on conditions find if
   they are digit cancelling or not, then multiply the valid fractions.

   Answer is the reduced denominator therefore we need to find gcd
   of numerator and denominator and divide that by denominator to
   get our answer. 
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// only for non-trivial solutions
bool digitCancellingFractions(int num, int denom){
    if(num > denom){
        return false; //fraction is more than 1
    }
    if(num==denom){
        return false;
    }
    if(num%10==0 && denom%10==0){
        return false; //trivial solution
    }

    int num_ones = num%10;
    int num_tens = num/10;
    int denom_ones = denom%10;
    int denom_tens = denom/10;
    
    double actual_ans = (double)num/(double)denom;
    double digit_cancel_ans;

    // can be done better
    if(num_tens == denom_tens){
        digit_cancel_ans = (double)num_ones/(double)denom_ones;
    }
    else if(num_tens == denom_ones){
        digit_cancel_ans = (double)num_ones/(double)denom_tens;
    }
    else if(num_ones == denom_tens){
        digit_cancel_ans = (double)num_tens/(double)denom_ones;
    }
    else if(num_ones == denom_ones){
        digit_cancel_ans = (double)num_tens/(double)denom_tens;
    }
    else{
        return false;
    }

    if(actual_ans == digit_cancel_ans){
        return true;
    }
    return false;
}

int main()
{
    int init_num = 1;
    int init_denom = 1;

    // Iterate through solution space
    for(int i=10;i<=99;i++){
        for(int j=10;j<=99;j++){
            if(digitCancellingFractions(i,j)){
                init_num*=i;
                init_denom*=j;
                //cout<<i<<"/"<<j<<endl;
            }
        }
    }

    int reduced_denom = init_denom/gcd(init_num, init_denom);
    
    cout<<reduced_denom<<endl;
    
    return 0;
}
