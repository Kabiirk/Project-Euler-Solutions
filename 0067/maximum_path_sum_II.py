'''
Problem 67
By starting at the top of the triangle below and moving to adjacent numbers on the row below,
the maximum total from top to bottom is 23.

   3
  7 4
 2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'),
a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to
solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every
second it would take over twenty billion years to check them all.

There is an efficient algorithm to solve it. ;o)

Answer : 7273
'''

'''
TIPS:
Similar to Problem 18, the same algorithm scales well even for
this problem. As explained below :

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
collapses to one number - 23, which is our answer in this case.

'''

num_triangle = []
'''
num_triangles = 
[
   [59,  0,  0,  0,  0, ..  0],
   [73, 41,  0,  0,  0, ..  0],
   [52, 40,  9,  0,  0, ..  0],
   [26, 53,  6, 34,  0, ..  0],
   [10, 51, 87, 86, 81, ..  0],
   [61, 95, 66, 57, 25, .. 68],
   ......
]

'''
with open('p067_triangle.txt') as f:
   while True:
      line = f.readline()
      if not line:
         break
      num_array = list(map(int, line.strip().split(" ")))
      if(len(num_array) == 0):
            break
      else:
         num_triangle.append(num_array)

# Pad array with 0's at the end
# Dynamically get length of last array
# which is the largest array
n = len(num_triangle[len(num_triangle)-1])
for array in num_triangle:
   for i in range(len(array),100):
      array.append(0)

def maxPathSum(triangle):
   # Going up the triangle (bottom up addition)
   # needs to go from 98 -> 0
   for i in range(len(triangle)-2,-1, -1):
      # setting item @ index of above array as higher sum in the pair.
      for j in range(0,i+1):
         triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1])
                          #     Left Child        Right Child
   return triangle[0][0]

print(maxPathSum(num_triangle))