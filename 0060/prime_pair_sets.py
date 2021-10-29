'''
Problem 60
The primes 3, 7, 109, and 673, are quite remarkable.
By taking any two primes and concatenating them in
any order the result will always be prime. For example,
taking 7 and 109, both 7109 and 1097 are prime.
The sum of these four primes, 792, represents the
lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which
any two primes concatenate to produce another prime.

Answer : 26033
'''

'''
TIPS:
Generate prime list,
for ath prime
    for bth prime
        check if a,b & b,a concatenations are prime
                for cth prime
                    check if a,c & b,c concatenations are prime
                        for dth prime
                            check if a,d & b,d & c,d concatenations are prime
                                for eth prime
                                    check if a,e & b,e & c,e & d,e concatenations are prime
                                        if true
                                            store and print a+b+c+d+e

An alternate/SLIGHTLY faster Set approach :
https://www.mathblog.dk/project-euler-60-primes-concatenate/
'''

import random

def sieveOfEratosthenes(limit):
    a = [True] * limit                          # Initialize the primality list
    a[0] = a[1] = False
    prime_list = []

    for (i, isprime) in enumerate(a):
        if isprime:
            for n in range(i*i, limit, i):     # Mark factors non-prime
                a[n] = False

    for i in range(limit):
        if(a[i]):
            prime_list.append(i)

    return prime_list

# Miller-Rabin Primality test
# required since some concatenated primes can
# may not be present in list
def isPrime(n, k=3):
    
    # Implementation uses the Miller-Rabin Primality Test
    # The optimal number of rounds for this test is 40
    # See http://stackoverflow.com/questions/6325576/how-many-iterations-of-rabin-miller-should-i-use-for-cryptographic-safe-primes
    # for justification

    # If number is even, it's a composite number
    if n == 2:
        return True

    if n % 2 == 0:
        return False

    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = random.randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

def concatPrime(a, b):
    str_a = str(a)
    str_b = str(b)
    if(isPrime(int(str_a+str_b) )and isPrime(int(str_b+str_a))):
        return True
    return False


prime_list = sieveOfEratosthenes(10000)
five_sum = 0


for a in prime_list:
    # b is second number
    for b in prime_list:
        # check if b is less than a
        if b < a:
            continue
        # check if a and b satisfy the condition
        if concatPrime(a, b):
            # c is the third number
            for c in prime_list:
                # check if c is less than b
                if c < b:
                    continue
                # check if a,c and b, c satisfy the condition
                if concatPrime(a, c) and concatPrime(b, c):
                    # d is the fourth number
                    for d in prime_list:
                        # check if d is less than c
                        if d < c:
                            continue
                        # check if (a,d), (b,d) and (c,d) satisfy the condition
                        if concatPrime(a, d) and concatPrime(b, d) and concatPrime(c, d):
                            # e is the fifth prime
                            for e in prime_list:
                                # check if e is less than d
                                if e < d:
                                    continue
                                # check if (a, e), (b, e), (c, e) and (d, e) satisfy condition
                                if concatPrime(a, e) and concatPrime(b, e) and concatPrime(c, e) and concatPrime(d, e):
                                    five_sum =  a+b+c+d+e

print(five_sum)