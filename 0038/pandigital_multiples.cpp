/*
Problem 38
Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576.
We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5,
giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed
as the concatenated product of an integer with (1,2, ... , n) where n > 1?

Answer : 932718654
*/

/*
TIPS:
As taken from : https://www.mathblog.dk/project-euler-38-pandigital-multiplying-fixed-number/
(Beautiful explanation for explaining solution space)

First of all the fixed number must contain less than 5 digits,
since n has to be greater than 1.

Second thing to not in our analysis is that we are given a
candidate which starts with 9, so the fixed number we need to
find needs to start with 9 as well which gives us some properties
to use in the analysis.

If the fixed number is 2 digit we wont be able to generate a 9 digit number
since n = 3 yields an 8 digit number and n=4 yields an 11 digit number.
Same goes for 3 digit numbers where we end at 7 or 11 digits in the result.
That leaves us with a four digit number starting with 9.

So already now we can limit the search to numbers between 9123 and 9876 a mere 753 numbers.

We can rather easily limit it a bit more. If the second digit is >4 then we get a carry over
which results in the multiplying by 2 part will yield 19xxx instead of 18xxx and
thus we have two 9’s which are not possible solutions. Further more non of the digits
can be 1 since we will end up with a solution candidate with two 1’s in it.

So the solution space can be shrunk to numbers between 9234 and 9487 which means
we would need to check 253 solutions.
*/

#include <iostream>

using namespace std;

long concat(long a, long b) {
    long c = b;
    while (c > 0) {
        a *= 10;
        c /= 10;
    }
    return a + b;
}

bool isPandigital(long n) {
    int digits = 0;
    int count = 0;
    int tmp;
 
    while (n > 0) {
        tmp = digits;
        digits = digits | 1 << (int)((n % 10) - 1);
        if (tmp == digits) {
            return false;
        }
 
        count++;
        n /= 10;
    }
    return digits == (1 << count) - 1;
}

int main()
{
    long result = 0;
    for (long i = 9387; i >= 9234; i--) {
        result = concat(i, 2*i);
        if(isPandigital(result)){
            break;
        }
    }

    cout<<result<<endl;

    return 0;
}
