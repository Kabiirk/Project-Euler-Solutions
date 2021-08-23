/*
Problem 32
We shall say that an n-digit number is pandigital if it makes use
of all the digits 1 to n exactly once; for example, the 5-digit
number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254,
containing multiplicand, multiplier, and product is 1 through 9
pandigital.

Find the sum of all products whose multiplicand/multiplier/product
identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to
only include it once in your sum.

Answer : 45228
*/

/*
TIPS:
1) Brute Force
   Create all pandigital permutations of a,b,c
   Then check if a*b=c , store c in a set to ensure
   only distinct values are stored even if we get a
   repeat pandigital product.
   At the end, add all values of the set to get answer.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int limit = 9;

    vector<unsigned int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    digits.resize(limit);

    // valid & only distinct pan-digital products
    set<unsigned int> valid_products;

    // a*b = c
    do{
        for(unsigned int len_a = 1; len_a < limit; len_a++){
            for (unsigned int len_b = 1; len_b < limit; len_b++){
                
                unsigned int len_c = limit - len_a - len_b;

                if(len_c < len_a || len_c < len_b){
                    break;
                }

                // currently used position in "digits"
                unsigned int pos = 0;
                
                unsigned int a = 0;
                for (unsigned int i = 1; i <= len_a; i++){
                    a *= 10;
                    a += digits[pos++];
                }
                
                unsigned int b = 0;
                for (unsigned int i = 1; i <= len_b; i++){
                    b *= 10;
                    b += digits[pos++];
                }
                
                unsigned int c = 0;
                for (unsigned int i = 1; i <= len_c; i++){
                    c *= 10;
                    c += digits[pos++];
                }
                
                if(a*b == c){
                    valid_products.insert(c);
                }
            }
        }
    }while(next_permutation(digits.begin(), digits.end()));

    // Calc sum
    unsigned int sum = 0;
    for (auto x : valid_products){
        sum += x;
    }
    cout << sum << endl;

    return 0;
}
