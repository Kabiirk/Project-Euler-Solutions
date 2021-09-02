/*
Problem 40
An irrational decimal fraction is created by concatenating
the positive integers:

0.123456789101112131415161718192021...
             ^
It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d_1 × d_10 × d_100 × d_1000 × d_10000 × d_100000 × d_1000000

Answer : 210
*/

/*
TIPS:
We have :
9, 1 digit numbers (1-9)
90, 2 digit numbers (10-99)
900, 3 digit numbers (100-999)
9000, 4 digit numbers (1000-9999)
90000, 5 digit numbers (10000-99999)
900000, 6 digit numbers (100000-999999)

Which will total to 5,888,889 digits. But we only need 1,000,000, so that
9 x 1 digit
90 x 2 digit
900 x 3 digit
9000 x 4 digit
90000 x 5 digit
n x 6 digit

this implies :
9*1 + 90*2 + 900*3 + 9000*4 + 90000*5 + n*6 = 1000000
_     __     ___     ____     _____     _

So the value of n is approximately 85186 

now as :
9 + 90 + 900 + 9000 + 90000 + 85186 = 185185
This means we will have to do iterations until 185186.

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "";
    for(int i = 0; i<185186; i++){
        a+=to_string(i);
    }

    //int final_product = a[9];
    int a_1 = a[1] - '0';
    int a_10 = a[10]  - '0';
    int a_100 = a[100]  - '0';
    int a_1000 = a[1000]  - '0';
    int a_10000 = a[10000]  - '0';
    int a_100000 = a[100000]  - '0';
    int a_1000000 = a[1000000]  - '0';
    int champernowne_constant = a_1 * a_10 * a_100 * a_1000 * a_10000 * a_100000 * a_1000000;

    cout<<champernowne_constant<<endl;

    return 0;
}
