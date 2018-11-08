from math import sqrt


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

primes = [2]

i = 3
while True:
    print(i, "\r", end="")
    if is_prime_basic(i):
        primes.append(i)
    else:
        for x in primes:
            t = sqrt((i - x) / 2)
            dr = False
            if int(t) == t:
                dr = True
                break
        if not dr:
            print(i)
            break
    i += 2
