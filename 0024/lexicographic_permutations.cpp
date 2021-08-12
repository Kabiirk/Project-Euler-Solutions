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

Essentially 

_ _ _ _ _ _ _ _ _ _ => 10! Permutations total

Number                       Permutation Range (Number covered)
_  _  _  _  _  _  _  _  _  _                0
0 [            9!           ]         0 -> 362880 Permutations (i.e. Permutations from 0 to 362880 start with 0)
1 [            9!           ]        362881 -> 725760 Permutations
2 [            9!           ]        725761 -> 1088640  (Crossed Milllionth Permutation, so our number starts with 2 and ur millionth permutation is in the 3rd interval)

2  0 [          8!          ]        725761 -> 
_  _  _  _  _  _  _  _  _  _        725760
_  _  _  _  _  _  _  _  _  _        725760
_  _  _  _  _  _  _  _  _  _        725760
_  _  _  _  _  _  _  _  _  _        725760
_  _  _  _  _  _  _  _  _  _        725760
_  _  _  _  _  _  _  _  _  _        725760
_  _  _  _  _  _  _  _  _  _        725760
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
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = arr.size();
	int remain = 1000000;
	
	vector<int> new_arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i = 1;
	while(remain != 0){
		int j = remain / factorial(n-i);
		remain = remain % factorial(n-i);
		new_arr[i-1] = arr[j];
		i++;
	}
	
	
    for(int i = 0; i<new_arr.size(); i++){
		cout<<new_arr[i];
	}

    return 0;
}
