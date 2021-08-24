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

Answer : 6857
*/

/*
TIPS:
2 digit fractions
i.e. (10->99)/(10->99)

fraction should be lesser than 1
i.e. numerator < denominator
*/

#include <iostream>

using namespace std;

// only for non-trivial solutions
bool digitCancellingFractions(int num, int denom){
    if(num%10==0 && denom%10==0){
        return false; //trivial solution
    }
    if(num > denom){
        return false; //fraction is more than 1
    }

    int num_ones = num%10;
    int num_tens = num/10;
    int denom_ones = denom%10;
    int denom_tens = denom/10;
    cout<<num_tens<<"-"<<num_ones<<"/"<<denom_tens<<"-"<<denom_ones<<endl;
    
    double actual_ans = (double)num/(double)denom;

    bool num_ones_cancel = (num_ones==denom_ones)||(num_ones==denom_tens);
    bool num_tens_cancel = (num_tens==denom_ones)||(num_tens==denom_tens);
    cout<<num_ones_cancel<<endl;
    cout<<num_tens_cancel<<endl;
    cout<< (int)num_ones_cancel*num_ones + (int)num_tens_cancel*num_tens <<endl;
    cout<< (int)num_ones_cancel*denom_ones + (int)num_tens_cancel*denom_tens <<endl;

    double digit_cancel_ans = (double)((int)num_ones_cancel*num_ones + (int)num_tens_cancel*num_tens)/(double)((int)num_ones_cancel*denom_ones + (int)num_tens_cancel*denom_tens) ;
    cout<<digit_cancel_ans<<endl;
    cout<<actual_ans<<endl;

    if(actual_ans == digit_cancel_ans){
        cout<<num<<"hjk"<<denom<<endl;
        return true;
    }
    return false;
}

int main()
{
    int a = (int)digitCancellingFractions(49,98);
    //cout<<a<<endl;
    
    return 0;
}
