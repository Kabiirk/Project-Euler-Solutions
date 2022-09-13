'''
Problem 71

Consider the fraction, n/d, where n and d are positive integers.
If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that 2/5 is the fraction immediately to the left of 3/7.

By listing the set of reduced proper fractions for d ≤ 1,000,000 in ascending order of size,
find the numerator of the fraction immediately to the left of 3/7.

Answer :
'''

'''
TIPS:
Say p/q < a/b
=> pb <= aq
=> pb <= aq-1
=> p <= (aq-1)/b [subtracting 1 in case RHS is an integer , it would give an equality]
'''

LIMIT = 1000000
maxnumer = 0
maxdenom = 1
for d in range(1, LIMIT + 1):
    n = d * 3 // 7
    if d % 7 == 0:
        n -= 1
    if n * maxdenom > d * maxnumer:  # n/d > maxdenom/maxnumer
        maxnumer = n
        maxdenom = d
print(str(maxnumer))
