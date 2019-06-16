from math import sqrt


def is_penta(k):
    n = (1 + sqrt(1 + 24 * k)) / 6
    if int(n) == n:
        return True
    return False

assert is_penta(92)

D = 5482660
for i in range(1, 100000):
    print(i, "\r", end="")
    a = i * (3*i - 1) / 2
    for j in range(i+1, 100000):
        b = j * (3*j - 1) / 2
        s = a + b
        d = abs(a - b)
        if d >= D:
            break
        elif is_penta(s) and is_penta(d):
            D = d

print()
print(D)
