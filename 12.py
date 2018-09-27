from functools import reduce

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


def prime_factorisation(n, primes):
    factorisation = []
    i = 0
    temp = [0,0]
    while n != 1:
        p = primes[i]
        while n % p == 0:
            temp = [p, temp[1] + 1]
            n = n // p
        factorisation.append(tuple(temp))
        temp[1] = 0
        i += 1
    return factorisation

def num_divisors(n, primes):
    if n < 2:
        return 1
    factorisation = prime_factorisation(n, primes)
    return reduce(lambda x,y:  x*y, [x[1]+1 for x in factorisation])


primes = []
M = 2000000
for i in range(2, M):
    print(i, "\r", end="")
    if is_prime_basic(i):
        primes.append(i)
print()

s , i = 0, 1
nd = num_divisors(s, primes)
while nd < 500:
    s += i
    nd = num_divisors(s, primes)
    i += 1
    print(i - 1, nd, "\r", end="")

print("\n", s)