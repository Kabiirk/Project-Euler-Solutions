/*
Problem 28
Starting with the number 1 and moving to the right in a clockwise direction
a 5 by 5 spiral is formed as follows:

[21]  22   23   24  [25]
 20   [7]   8   [9]  10
 19    6   [1]   2   11
 18   [5]   4   [3]  12
[17]  16   15   14  [13]

It can be verified that the sum of the numbers on the diagonals (inside [] brackets)
is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
formed in the same way?

Answer : 669171001
*/

/*
TIPS:
1) Half-Diagonal Approach:
Here, instead of summing up 2 diagonals, we break them into 2 half-diagonals

so instead of 2 diagonals:
bottom-left corner   ->   top-right corner
bottom-righr corner  ->   top_left corner

we consider diagonals originating from the center of sprial (i.e. from 1) 
and going towards the corner :
1 -> Top-Right corner (top_right)
1 -> Top-Left corner (top_left)
1 -> Bottom-Left corner (bottom_left)
1 -> Bottom-Right corner (bottom_right)

As depicted below :
    ▲           ▲
    └┐         ┌┘
    .└┐       ┌┘.
    43└┐     ┌┘49
     21└┐   ┌┘25
       7└┬─┬┘9
         │1│
       5┌┴─┴┐3
     17┌┘   └┐13
    37┌┘     └┐31
    .┌┘       └┐.
    ┌┘         └┐
    ▼           ▼

Note :
top_right + bottom_left = bottom-left corner   ->   top-right corner
top_left + bottom_right = bottom-righr corner  ->   top_left corner

The number-series in each of these diagonals can be written as
Top-Right:
n = 0; 1                                  = 1

          ┌─┐
n = 1; 1 +│8│                             = 9
          └─┘
              ┌─────┐
n = 2; 1 + 8 +│8 + 8│                     = 25
              └─────┘
                      ┌─────────┐
n = 3; 1 + 8 + 8 + 8 +│8 + 8 + 8│         = 49
                      └─────────┘

Top-Left:
n = 0; 1                                  = 1

          ┌─┐
n = 1; 1 +│6│                             = 7
          └─┘
              ┌─────┐
n = 2; 1 + 6 +│6 + 8│                     = 21
              └─────┘
                      ┌─────────┐
n = 3; 1 + 6 + 6 + 8 +│6 + 8 + 8│         = 43
                      └─────────┘

Bottom-Left:
n = 0; 1                                  = 1

          ┌─┐
n = 1; 1 +│4│                             = 5
          └─┘
              ┌─────┐
n = 2; 1 + 4 +│4 + 8│                     = 17
              └─────┘
                      ┌─────────┐
n = 3; 1 + 4 + 4 + 8 +│4 + 8 + 8│         = 37
                      └─────────┘

Bottom-Right:
n = 0; 1                                  = 1

          ┌─┐
n = 1; 1 +│2│                             = 3
          └─┘
              ┌─────┐
n = 2; 1 + 2 +│2 + 8│                     = 13
              └─────┘
                      ┌─────────┐
n = 3; 1 + 2 + 2 + 8 +│2 + 8 + 8│         = 31
                      └─────────┘

Therefore, from the given series we observe
the general forumula for nth term of the half-diagonals
can be written as :
                ┌────────────────────┐
n = n; 1 + ... +│inner_diff + (n-1)*8│
                └────────────────────┘
where inner_diff = inner difference of the 1st spiral after 1
i.e. 
inner_diff(Top-Right) = 9-1 = 8
inner_diff(Top-Left) = 7-1 = 6
inner_diff(Bottom-Left) = 5-1 = 4
inner_diff(Bottom-Right) = 3-1 = 2

Based on the above formula, we write a common function halfDiagonalSum()
to calculate sum of terms in a half-diagonal (excluding 1)

Note : That is why limit starts from 1, otherwise
while adding all 4 diagonals to get the final sum,
1 would be added four times instead of one.
We add 1 after calculating sum of all 4 half-diagonals
to solve this problem.


2) A highly scalable solution with lesser complexity
ref.: https://euler.stephan-brumme.com/28/

3) A pure paper-only approach (can also be done as a one-liner code) :
https://www.mathblog.dk/project-euler-28-sum-diagonals-spiral/
*/

#include <iostream>

using namespace std;

int halfDiagonalSum(int first_term, int inner_diff, int limit){
	int n_term = first_term;
	int sum = 0;
	for(int n=1; n<=limit; n++){ //-2 because we are excluding 1 in the beginning
		n_term += inner_diff+(8*(n-1));
		sum+=n_term;
	}
	return sum;
}

int main()
{
	// moving anti-clockwise
	// Taking 500 instead of 1001 because only half the diagonal
	// in each direction is being considered
	// 500 because we do +1 in the end
	// to account for 1001st element of each half diagonal
	unsigned int top_right = halfDiagonalSum(1, 8, 500);
	unsigned int top_left = halfDiagonalSum(1, 6, 500);
	unsigned int bottom_left = halfDiagonalSum(1, 4, 500);
	unsigned int bottom_right = halfDiagonalSum(1, 2, 500);
	
	// Adding 1 here since it was excluded from
	// half-diagonals sum
	unsigned int final_sum = 1 + top_right + top_left + bottom_left + bottom_right;
	
    cout<< final_sum <<endl;
    return 0;
}
