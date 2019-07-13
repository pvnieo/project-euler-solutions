n, d = 1, 1

for a in range(1, 10):
    for b in range(1, a):
        for x in range(1, b):
            if (x * 10 + a) * b == (a * 10 + b) * x:
                n *= x
                d *= b

print(d, n)
