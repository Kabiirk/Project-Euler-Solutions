'''
Problem 70

Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of
positive numbers less than or equal to n which are relatively prime to n.
For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.

Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

Find the value of n, 1 < n < 107, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.

Answer : 8319823
'''

'''
TIPS:

'''

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

def is_permutation_better(a, b):
    '''
    Counts how many frequency of digits in a number
    i.e. how many 1,2,...,9's a number has

    2 Numbers are Permutations of each other
    if they have the same fingerprint.

    Going through 'a' increments fingerprint indexes,
    going through 'b' decrements fingerprint indexes
    if both have same digits, final sum is 0.
    as all counts incremented while traversing a
    are reduced to zero while traversng through b
    '''
    fingerprint_a = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    fingerprint_b = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    #                0  1  2  3  4  5  6  7  8  9

    # Handle -ve numbers
    # Modulos of -ve numbers are complicated,
    # so converting them to positives for now
    # since that won't change any digits, only signs
    # Ref.: https://math.stackexchange.com/questions/2179579/how-can-i-find-a-mod-with-negative-number
    # Note this is done under the assumption that -1234 is a valid permutation of -4321
    if a<0:
        a = -a
    if b<0:
        b = -b

    while a>0:
        fingerprint_a[a%10]+=1
        a = a//10

    while b>0:
        fingerprint_b[b%10]+=1
        b = b//10

    for k in range(len(fingerprint_a)):
        if(fingerprint_a[k]!=fingerprint_b[k]):
            return False

    # Simple approach
    # return sorted(str(a))==sorted(str(b))
    return True

def solve(limit):
    primes = sieve_of_eratosthenes(int(1.2*(limit**0.5)))
    min_q, min_n, i = 2,0,0
    for p1 in primes:
        i+=1
        for p2 in primes[i:]:
            if (p1+p2)%9 != 1:
                continue
            n = p1*p2
            if n>limit:
                return min_n
            phi = (p1-1)*(p2-1)
            q = n/float(phi)
            if is_permutation_better(phi, n) and min_q>q:
                min_q, min_n = q,n
    return 0


limit = 10000000
print(solve(limit))