/*
Problem 43
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of
each of the digits 0 to 9 in some order, but it also has a rather interesting
sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

> d2d3d4 = 406 is divisible by 2
> d3d4d5 = 063 is divisible by 3
> d4d5d6 = 635 is divisible by 5
> d5d6d7 = 357 is divisible by 7
> d6d7d8 = 572 is divisible by 11
> d7d8d9 = 728 is divisible by 13
> d8d9d10 = 289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.

Answer : 16695334890
*/

/*
TIPS:
Using substr() & next_permutation() to help with
generating permutaion and checking substring divisiblity
for prime_divisor list, add every pan-digital number
satisfying the conditions

NOTE : Reffer to the below link for an obvious-yet-amazing no-code solution
https://www.mathblog.dk/project-euler-43-pandigital-numbers-sub-string-divisibility/
*/

#include <string>
#include <iostream>
#include <algorithm>

typedef unsigned long long ULL;

using namespace std;

// custom string -> number conversion function
ULL strToNum(string x){
    ULL result = 0;
    for(auto i : x){
        result *= 10;
        result += i - '0';
    }

    return result;
}

int main()
{
    string pandigital_num = "0123456789";

    unsigned int prime_divisor[] = {2, 3, 5, 7, 11, 13, 17};

    ULL sum = 0;

    do{
        bool is_valid = true;

        for(unsigned int i = 0; i+2<9; i++){

            // generate substring & check against prime divisiblity :
            // pandigital_num[1..3] % 2
            // pandigital_num[2..4] % 3
            // pandigital_num[3..5] % 5
            // pandigital_num[4..6] % 7
            // pandigital_num[5..7] % 11
            // pandigital_num[6..8] % 13
            // pandigital_num[7..9] % 17
            //
            // indexes are off by one because array indexing starts from 0
            string num_substring = pandigital_num.substr(i+1, 3);
            if(strToNum(num_substring)%prime_divisor[i] != 0){
                is_valid = false;
                break;
            }
        }

        // if permutation valid, add to sum
        if(is_valid){
            sum += strToNum(pandigital_num);
        }
    }while(next_permutation(pandigital_num.begin(), pandigital_num.end())); // keep generating permutations

    cout<<sum<<endl;

    return 0;
}
