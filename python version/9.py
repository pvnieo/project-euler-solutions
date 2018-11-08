
M = 0
for a in range(1000):
    for b in range(1000-a):
        c = 1000 - a - b
        if a ** 2 + b ** 2 == c ** 2 and a * b * c > M:
            M = a * b * c

print(M)
