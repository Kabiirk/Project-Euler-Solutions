/*
Problem 42
The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1);
so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical
position and adding these values we form a word value. For example, the word value
for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we
shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing
nearly two-thousand common English words, how many are triangle words?

Answer : 
*/

/*
TIPS:
Naive Approach : The approach is simple, just factorise the 
given number by dividing it with the divisor of a number and 
keep updating the maximum prime factor. Complexity : O(sqrt(n))

Better Alternative : Sieve of Eratosthenes. Complexity : O(n*log2*log2(n))

Even Better : Sieve of Atkin (slightly faster than Sieve of Eratosthenes)
*/

#include <iostream>

using namespace std;

int main()
{
    cout<<"Hello Euler !!"<<endl;
    return 0;
}