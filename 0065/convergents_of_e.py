'''
Problem 65

.

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
