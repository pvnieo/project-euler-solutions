from itertools import permutations, combinations_with_replacement


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

combs = combinations_with_replacement(range(0, 10), 4)
pp = []
for combination in combs:
    if len(set(combination)) >= 3:
        perms = permutations(combination, 4)
        primes = []
        for x in perms:
            if x[0] == 0 or (x[0] == 0 and x[1] == 0):
                continue
            elif x[3] in [0, 2, 4, 6, 8]:
                continue
            else:
                n = int(''.join(map(str, x)))
                if is_prime_basic(n):
                    primes.append(n)
        if len(set(primes)) >= 3:
            primes = sorted(list(set(primes)))
            primes = [p for p in primes if sum([1 if abs(p-x) % 3330 == 0 else 0 for x in primes]) > 1]
            if len(primes) > 2:
                pp.append(tuple(primes))
print(pp)
