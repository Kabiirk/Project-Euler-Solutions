def sum_digits(n):
    r = 0
    while n:
        r, n = r + n % 10, n // 10
        
    return r

largest_sum = 0
# Additional
# a_max = 0
# b_max = 0

for a in range(2,101):
    for b in range(2,101):
        power_sum = sum_digits(a**b)
        if(power_sum > largest_sum):
            largest_sum = power_sum
            # a_max = a
            # b_max = b

# print(f'{a_max}^{b_max}')
print(largest_sum)