'''
Problem 65
The square root of 2 can be written as an infinite continued
fraction.

√2 = 1 + 1/( 2+1/( 2+1/( 2+1/(2+...) ) ) )

The infinite continued fraction can be written, √2 = [1,(2)], (2)
indicates that 2 repeats ad infinitum. In a similar way
√23 = [4, (1,3,1,8)].

It turns out that the sequence of partial values of continued
fractions for square roots provide the best rational approximations.
Let us consider the convergents for √2

1+1/2 = 3/2
1+1/(2+1/2) = 7/5
1+1/(2+1/(2+1/2)) = 17/12
1+1/(2+1/(2+1/(2+1/2))) = 41/29

Hence the sequence of the first ten convergents for √2 are:
1, 3 , 7 , 17 , 41 , 99 , 239 , 577 , 1393 , 3363 ......
  --- --- ---  ---  ---- ----- ----- ------ -----
   2 , 5 , 12 , 29 , 70 , 169 , 408 ,  985 , 2378

What is most surprising is that the important mathematical
constant :
e = [2; 1, 2, 1, 1, 4, 1, 1, 6, 1, ... , 1, 2k, 1, ...]

The first ten terms in the sequence of convergents for e are:
1, 3 , 8 , 11 , 19 , 87 , 106 , 193 , 1264 , 1457 ......
      --- ---  ---- ---- ----- ----- ------ ------
       3 ,  4 ,  7 , 32 ,  39 ,  71 ,  465 ,  536

The sum of digits in the numerator of the 10th convergent is :
1+4+5+7 = 17

Find the sum of digits in the numerator of the 100th
convergent of the continued fraction for e.

Answer : 272
'''

'''
TIPS:
The value of the continuous fraction repeats with the pattern 1,2k,1...

numerator_i = numerator_{i-1} * fraction_{i-1} + numerator_{i-2}
'''

def convergents_of_e(N):
    n = 2
    prev_n = 1
    
    fract = 1
    for k in range(2, N+1):
        temp = prev_n
        if (k % 3 == 0):
            fract = 2 * int(k/3)
        else:
            fract = 1
        prev_n = n
        n = fract * prev_n + temp
    
    sum = digit_sum(n)
    return sum

def digit_sum(num):
    sum = 0
    while num > 0:
        sum = sum + (num % 10)
        num = num // 10
    return sum


print(convergents_of_e(100))
