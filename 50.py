
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


def get_longest_prime(n):
    primes = [i for i in range(n+1) if is_prime_basic(i)]
    M, P = 0, 1
    for i, p in enumerate(primes):
        for j in range(i+1, len(primes)):
            p += primes[j]
            if p > n:
                break
            elif (j - i) > M and p in primes:
                M = j - i + 1
                P = p
    return M, P

print(get_longest_prime(1000000))
