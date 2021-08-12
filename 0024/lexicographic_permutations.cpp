/*
Problem 24
A permutation is an ordered arrangement of objects. For example,
3124 is one possible permutation of the digits 1, 2, 3 and 4.
If all of the permutations are listed numerically or alphabetically,
we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

Answer : 2783915460
*/

/*
TIPS:
First we want to figure out, which number is first in the millionth lexicographical permutation.
The last nine digits can be ordered in 9! = 362880 ways. So the first 362880 permutations start
with a 0. The permutations from 362881 to 725760 start with a 1 and then the permutations from
725761 to 1088640 starts with a 2. Based on that it is clear that the millionth permutation is
in the third interval, and thus must start with a 2.

So the 725761st permutation is 2013456789. So now we miss 274239 permutation to reach the goal,
so we can start figuring out the second number.

Since 8! = 40320, we get get that changing the number six times we reach the permutations from 241920 – 282240.
So we need to take the 7th number in the list. Since the list excludes 2 we end up with 7 as the second digit
of the millionth permutation. We can then continue all the way through until we got all digits.

Essentially :

_  _  _  _  _  _  _  _  _  _    =>   10! Permutations total

Number                                Permutation Range (Numbers covered)
_  _  _  _  _  _  _  _  _  _                       0

0 [            9!           ]                    0 - 362,880 (i.e. Permutations from 0 to 362880 start with 0 & covers numbers till 362,880th Permutation)
1 [            9!           ]              362,881 - 725,760
2 [            9!           ]              725,761 - 1,088,640  (Crossed Milllionth Permutation, so our number starts with 2 and our millionth permutation is in the 3rd interval)

2  0 [          8!          ]              725,761 - 766,080
2  1 [          8!          ]              766,081 - 806,400
2  3 [          8!          ]              806,401 - 846,720
2  4 [          8!          ]              846,721 - 887,040
2  5 [          8!          ]              887,041 - 927,360
2  6 [          8!          ]              927,361 - 967,680
2  7 [          8!          ]              927,361 - 1,008,000 (Crossed Milllionth Permutation, so our number starts with 27 and our millionth permutation is in the 6th interval)

2  7  0 [        7!         ]              967,681 - 972,720
2  7  1 [        7!         ]              972,721 - 977,760
2  7  3 [        7!         ]              977,761 - 982,800
2  7  4 [        7!         ]              982,801 - 987,840
2  7  5 [        7!         ]              987,841 - 992,880
2  7  6 [        7!         ]              997,921 - 997,920
2  7  8 [        7!         ]              997,921 - 1,002,961 (Crossed Milllionth Permutation, so our number starts with 278 and our millionth permutation is in the 6th interval)
                                     
.... We keep repeating this process until ....

2  7  8  3  9  1  5  0  6  4                 999,998th Permutation
2  7  8  3  9  1  5  4  0  6                 999,999th Permutation
2  7  8  3  9  1  5  4  6  0               1,000,000th Permutation
*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

int main()
{
	vector<int> digit_basket = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = digit_basket.size();
	int remainder = 1000000 - 1;
	
	vector<int> final_number = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	for(int i = 1; i<=n; i++){
		int j = remainder / factorial(n-i);
		remainder = remainder % factorial(n-i);
		final_number[i-1] = digit_basket[j]; // Assign to final_number before removing
		remove(digit_basket.begin(), digit_basket.end(), digit_basket[j]); // Since no repetition is considered in our permutation
	}
	
	
    for(int i = 0; i<final_number.size(); i++){
		cout<<final_number[i];
	}

    return 0;
}
