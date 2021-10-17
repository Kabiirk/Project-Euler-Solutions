num = 1
den = 1

# counter
counter = 0

# 1000 iterations
for i in range(1000):
    num1 = num + 2*den
    den1 = num + den
    if len(str(num1)) > len(str(den1)):
        counter += 1
    num = num1
    den = den1

# printing the counter
print(counter)