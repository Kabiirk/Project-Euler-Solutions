'''
Problem 69 (nice)

Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.

Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.

n    Relatively Prime    φ(n)    n/φ(n)
2    1                    1        2
3    1,2                  2        1.5
4    1,3                  2        2
5    1,2,3,4              4        1.25
6    1,5                  2        3
7    1,2,3,4,5,6          6        1.1666...
8    1,3,5,7              4        2
9    1,2,4,5,7,8          6        1.5
10   1,3,7,9              4        2.5

It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.

Answer : 510510
'''

'''
TIPS:
Multiplying primes until we reach the largest number less than 1,000,000.
'''

# TODO:
# implements Sieve of Eratosthenes to poppulate primes

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

res = 1
i = 0
limit = 1000000
primes = sieve_of_eratosthenes(limit)

while(res*primes[i] < limit):
    res*=primes[i]
    i+=1

print(res)

"""
##    ## ####  ######  ######## 
###   ##  ##  ##    ## ##       
####  ##  ##  ##       ##       
## ## ##  ##  ##       ######   
##  ####  ##  ##       ##       
##   ###  ##  ##    ## ##       
##    ## ####  ######  ######## 
"""