
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

primes = []


def prime_factorisation(n):
    global primes
    if n in primes:
        return [(n, 1)]
    elif is_prime_basic(n):
        primes.append(n)
        return [(n, 1)]
    else:
        factorisation = []
        i = 0
        while n != 1:
            p = primes[i]
            temp = [p, 0]
            while n % p == 0:
                temp = [p, temp[1] + 1]
                n = n // p
            if temp[1] != 0:
                factorisation.append(tuple(temp))
            temp[1] = 0
            i += 1
        return factorisation


i = 2
while True:
    distinct = 4
    dr = True
    for j in range(distinct):
        if len(prime_factorisation(i + j)) < distinct:
            i += 1
            dr = False
            break
    if dr:
        print(i)
        break
