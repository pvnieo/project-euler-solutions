from itertools import permutations


def is_prime_basic(x):
    if x <= 1:
        return False
    elif x <= 3:
        return True
    elif x % 2 == 0 or x % 3 == 0:
        return False
    i = 5
    while i ** 2 <= x:
        if x % i == 0 or x % (i+2) == 0:
            return False
        i += 6
    return True

M = -1

for i in range(9, 0, -1):
    pandigitals = permutations(range(i, 0, -1))
    for p in pandigitals:
        p = int("".join(map(str, p)))
        if p > M and is_prime_basic(p):
            M = p
    if M != -1:
        break

print(M)
