'''
Problem 68

Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.

         ┌───┐
         │ 4 │
         └───┤
             └─┐
               ├───┐
               │ 3 │
               ├───┤
             ┌─┘   └─┐
         ┌───┤       ├───┐   ┌───┐
         │ 1 ├───────┤ 2 ├───┤ 6 │
         ├───┘       └───┘   └───┘
       ┌─┘
   ┌───┤
   │ 5 │
   └───┘

Working clockwise, and starting from the group of three with the numerically lowest external node (4,3,2 in this example),
each solution can be described uniquely. For example, the above solution
can be described by the set: 4,3,2; 6,2,1; 5,1,3.

It is possible to complete the ring with four different totals: 9, 10, 11, and 12.
There are eight solutions in total.

Total       Solution Set
9        4,2,3; 5,3,1; 6,1,2
9        4,3,2; 6,2,1; 5,1,3
10       2,3,5; 4,5,1; 6,1,3
10       2,5,3; 6,3,1; 4,1,5
11       1,4,6; 3,6,2; 5,2,4
11       1,6,4; 5,4,2; 3,2,6
12       1,5,6; 2,6,4; 3,4,5
12       1,6,5; 3,5,4; 2,4,6

By concatenating each group it is possible to form 9-digit strings;
the maximum string for a 3-gon ring is 432621513.

Using the numbers 1 to 10, and depending on arrangements,
it is possible to form 16- and 17-digit strings.
What is the maximum 16-digit string for a "magic" 5-gon ring?

         ┌───┐
         │   │
         └───┤
             └────┐
                  ├───┐         ┌───┐
                  │   │         │   │
                  ├───┤         ├───┘
             ┌────┘   └────┐   ┌┘
         ┌───┤             ├───┤
         │   │             │   │
         ├───┤             ├───┘
    ┌────┘   └┐           ┌┘
┌───┤         ├───┐   ┌───┤    ┌───┐
│   │         │   ├───┤   ├────┤   │
└───┘         └───┤   └───┘    └───┘
                  └┐
                   ├───┐
                   │   │
                   └───┘

Answer :
'''

'''
TIPS:

'''

from itertools import permutations
from itertools import combinations
# array of candidate solutions empty at the beginning
record = []

# choose 5 numbers for inner cells between 1 and 9; there are 9C5 combinations
# the problem ask for a 16-digit number, so 10 is not to be included in inner cells
cells = range(1,10)
inner_cells = [map(int,comb) for comb in combinations(cells,5)]

# code to calculate min and max couple in an array
def minCouple(array):
    answer = array[0]+array[-1]
    for i in range(len(array)-1):
        coupleSum = array[i] + array[i+1]
        if coupleSum < answer:
            answer = coupleSum
    return answer
    
def maxCouple(array):
    answer = 0
    for i in range(len(array)-1):
        if i==0:
            coupleSum = array[0]+ array[-1]
            if coupleSum > answer:
                answer = coupleSum
        else:
            coupleSum = array[i]+ array[i+1]
            if coupleSum > answer:
                answer = coupleSum
    return answer

# Algorithm
for array in inner_cells:
    pivot = array[0]
    perm_array = array[1:]
    perms = [map(int,perm) for perm in permutations(perm_array,4)]
    for perm in perms:
        checkArray = perm
        checkArray.insert(0,pivot)
        outerRing = [el for el in range(1,11) if el not in checkArray]
        xMax = minCouple(checkArray) + max(outerRing)
        xMin = maxCouple(checkArray) + min(outerRing)
        if xMax >= xMin:
            for x in range(xMin, xMax+1):
                i = checkArray[0]
                j = checkArray[1]
                k = checkArray[2]
                l = checkArray[3]
                m = checkArray[4]

                alpha = x-i-j
                beta = x-j-k
                gamma = x-k-l
                delta = x-l-m
                theta = x-m-i
                                
                outerCalculated = [alpha, beta, gamma, delta, theta]
                
                if sorted(outerCalculated) == sorted(outerRing):
                    a = [alpha, i, j]
                    b = [beta, j, k]
                    c = [gamma, k, l]
                    d = [delta, l, m]
                    e = [theta, m, i]
                    min_val = min(alpha, beta, gamma, delta, theta)
                    if alpha == min_val:
                        append = a+b+c+d+e
                    elif beta == min_val:
                        append = b+c+d+e+a
                    elif gamma == min_val:
                        append = c+d+e+a+b 
                    elif delta == min_val:
                        append = d+e+a+b+c 
                    elif theta == min_val:
                        append = e+a+b+c+d 
                    l = [str(i) for i in append]
                    s = ''.join(l)
                    integer_list = int(s) 
                    record.append(integer_list)
print(max(record))
