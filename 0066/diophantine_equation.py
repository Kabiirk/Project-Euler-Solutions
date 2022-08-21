'''
Problem 66

Consider quadratic Diophantine equations of the form:

x^2 – Dy^2 = 1

For example, when D=13, the minimal solution in x is 649^2 – 13×180^2 = 1.

It can be assumed that there are no solutions in positive integers when D is square.

By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:

3^2 – 2×2^2 = 1
2^2 – 3×1^2 = 1
9^2 – 5×4^2 = 1 <<
5^2 – 6×2^2 = 1
8^2 – 7×3^2 = 1

Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.

Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.

Answer :
'''

'''
TIPS:

'''
import math

result = 0
pmax = 0
 
for D in range(2,1000):
    limit = int(math.sqrt(D))
    if (limit * limit == D):continue

    m = 0
    d = 1
    a = limit

    numm1 = 1
    num = a

    denm1 = 0
    den = 1

    while(num*num - D*den*den != 1):
        m = d * a - m
        d = (D - m * m) // d
        a = (limit + m) // d

        numm2 = numm1
        numm1 = num
        denm2 = denm1
        denm1 = den

        num = a*numm1 + numm2
        den = a * denm1 + denm2

    if (num > pmax):
        pmax = num
        result = D

print(result)