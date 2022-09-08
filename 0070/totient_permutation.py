'''
Problem 70

Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of
positive numbers less than or equal to n which are relatively prime to n.
For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.

Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

Find the value of n, 1 < n < 107, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.

Answer :
'''

'''
TIPS:

'''
from cmath import inf


def sieve_of_eratosthenes(num_limit):
    a = [True]*num_limit
    a[0] = a[1] = False

    for (i, isprime) in enumerate(a):
        if isprime:
            for n in range(i*i, num_limit, i):
                a[n] = False

    prime_list = []
    for i in range(num_limit):
        if(a[i]):
            prime_list.append(i)

    return prime_list

best = 1;
phiBest = 1;
bestRatio = inf;
 
limit = 10000000;
primes = sieve_of_eratosthenes(5000);
 
for i in range(0, len(primes)):
    for j in range(i+1, len(primes)):
        n = primes[i]*primes[j]
        if (n > limit): break;
 
        phi = (primes[i] - 1) * (primes[j] - 1);
        ratio = n / phi;
