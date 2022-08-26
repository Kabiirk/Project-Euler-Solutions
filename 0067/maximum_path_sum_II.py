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

Answer :
'''

'''
TIPS:
Similar to Problem 18

'''

num_triangle = []
'''
num_triangles = 
[
   [59,  0,  0,  0,  0.  0],
   [73, 41,  0,  0,  0,  0],
   [52, 40,  9,  0,  0,  0],
   [26, 53,  6, 34,  0,  0],
   [10, 51, 87, 86, 81,  0],
   [61, 95, 66, 57, 25, 68],
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

# print(len(num_triangle[99]))
def maxPathSum(triangle):
   # bottom up addition
   m = len(triangle)
   n = len(triangle[0])
   for i in range(m-2,0, -1):
      print(i)
      for j in range(0,i+1):
         triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1])
                          #     Left Child        Right Child
   return triangle[0][0]

print(maxPathSum(num_triangle))