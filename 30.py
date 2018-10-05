
s = 0
for i in range(2, 400000):
    print(i, "\r", end="")
    sum_power = sum([int(x)**5 for x in str(i)])
    if i == sum_power:
        s += i

print(s)