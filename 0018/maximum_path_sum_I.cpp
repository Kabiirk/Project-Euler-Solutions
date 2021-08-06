/*
Problem 18
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

   3
  7 4
 2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

                            75
                          95  64
                        17  47  82
                      18  35  87  10
                    20  04  82  47  65
                  19  01  23  75  03  34
                88  02  77  73  07  63  67
              99  65  04  28  06  16  70  92
            41  41  26  56  83  40  80  70  33
          41  48  72  33  47  32  37  16  94  29
        53  71  44  65  25  43  91  52  97  51  14
      70  11  33  28  77  73  17  78  39  68  17  57
    91  71  52  38  17  14  91  43  58  50  27  29  48
  63  66  04  68  89  53  67  30  73  16  69  87  40  31
04  62  98  27  23  09  70  98  73  93  38  53  60  04  23

NOTE: As there are only 16384 routes, it is possible to solve this
problem by trying every route. However, Problem 67, is the same challenge
with a triangle containing one-hundred rows; it cannot be solved by brute
force, and requires a clever method! ;o)

Answer : 1074
*/

/*
TIPS:
We can go through the brute force by checking every possible path
but that is much time taking so we should try to solve this problem
with the help of dynamic programming which reduces the time complexity. 

first we should left shift every element and put 0 at each empty position
to make it a regular matrix, then our problem looks like minimum cost path. 
So, after converting our input triangle elements into a regular matrix we
should apply the dynamic programmic concept to find the maximum path sum. 

For e.g. we should write our matrix as: 
                +-       -+
   3            | 3,0,0,0 |
  7 4           | 7,4,0,0 |    ^
 2 4 6    =>    | 2,4,6,0 |    |  Direction we are adding in
8 5 9 3         | 8,5,9,3 |    |
                +-       -+

Algorithm :
1) Let T be an N row triangle.
2) Let S be the maximum sum descending from a given node: S[r][n] is the
   maximum sum descent starting from node (r,n).
3) The goal is to compute the value of S[0][0].
4) The values of S for the bottom row of T (row N-1) are just
   the values of the bottom row of T, nothing more:
   S[N-1][n] = T[N-1][n]
5) For all other nodes (r,n), the value of S[r][n] is
   the value of T[r][n] plus the greater value of:
   S[r+1][n] - the maximum sum descending from the left child.
   S[r+1][n+1] - the maximum sum descending from the right child.
6) So the recurrence relation is:
   S[N-1][n] = T[N-1][n]
   S[r][n] = T[r][n] + max(S[r+1][n], S[r+1][n+1])

E.g. of Approach :
We start with a triangle that looks like

   3
  7 4
 2 4 6
8 5 9 3

Applying the algorithm to the small problem we
will need three iterations. The first iteration
we apply the rule a + max(b,c) which creates a new triangle which looks as

   3
  7 4
10 13 15

Making the second iteration of the algorithm makes the triangle look

  3
20 19

And if we run the algorithm once more, the triangle
collapses to one number – 23 – which is the answer to the question.
*/

#include <bits/stdc++.h>

using namespace std;

int maxPathSum(int triangle[15][15], int m, int n){
	// bottom up addition
	for(int i=m-1; i>=0; i--){
		for(int j=0; j<=i; j++){
			triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
		}                  //     Left Child        Right Child
	}
	return triangle[0][0];
}

int main()
{
	int tri[15][15] = { {75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        {95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {20, 04, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {19, 01, 23, 75, 03, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {88, 02, 77, 73, 07, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0},
                        {99, 65, 04, 28, 06, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0},
                        {41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0},
                        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0},
                        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0},
                        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0},
                        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0},
                        {63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0},
                        {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
                      };
	
    cout<< maxPathSum(tri, 14,14) <<endl;
    return 0;
}
