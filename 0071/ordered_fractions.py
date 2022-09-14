'''
Problem 71

Consider the fraction, n/d, where n and d are positive integers.
If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that 2/5 is the fraction immediately to the left of 3/7.

By listing the set of reduced proper fractions for d ≤ 1,000,000 in ascending order of size,
find the numerator of the fraction immediately to the left of 3/7.

Answer : 428570
'''

'''
TIPS:
Ref.: https://en.wikipedia.org/wiki/Farey_sequence

Farey Sequence Approach
if n/d < a/b
n -> Numerator
d -> Denominator
Assuming n/d is the fraction that immediately precedes a/b,
then d*a - b*n = 1 [Farey neighbours]

In our case a/b = 3/7
i.e. n/d < 3/7
therefore, 3*d - 7*n = 1
or 3*d = 7*n + 1
which is the division algorithm
therefore, for d<=1000000, find n for which
3*d leave remainder 1

also n = (3*d - 1)/7
'''

def farey_neighbor(LIMIT, numertator, denomenator):
    c = LIMIT
    while((c*numertator)%denomenator != 1):
        c-=1
    return int((c*numertator - 1)/denomenator)

print(farey_neighbor(1000000, 3, 7))
