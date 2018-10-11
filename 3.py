from random import randint as rd
from math import sqrt
from math import gcd


N = 600851475143


def divisor_generator(n):
    for i in range(2, n // 2):
        if n % i == 0:
            yield n // i


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

for x in divisor_generator(N):
    if is_prime_basic(x):
        print()
        print(x, " is the one")
        break
    else:
        print(x, "\r", end="")
