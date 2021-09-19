/*
Problem 9
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

Answer : 31875000
*/

/*
TIPS:
a cannot be more than 332. If it is 333, b has to be at least 334 and c
at least 335, adding up to 1001(more than 1000). So limit a from 1 to 332.

b cannot be less than or equal to a. Limit b to a lower bound of a+1.

Also, b must be less than half of 1000-a (since c has to fill the other more-than-half).
So the upper bound of b has to be ceil((1000-a)/2-1).

*/

#include <iostream>
#include <cmath>

using namespace std;

bool checkPythagoreanTriplet(int a, int b, int c){
    if( ((int)pow(a,2) + (int)pow(b,2) ) == (int)pow(c,2)){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int a,b,c;
    
    for(a=0; a<=332; a++){
        for(b = a+1; b <= (int)ceil(((1000-a)/2)-1); b++){
            c = 1000 - a - b;
            if(checkPythagoreanTriplet(a, b, c)){
                cout<<a<<" * "<<b<<" * "<<c<<" = "<<a*b*c<<endl;
            }
        }
    }

    return 0;
}
