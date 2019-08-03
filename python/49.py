def sieve(n):
    is_prime = [True]*n
    is_prime[0] = False
    is_prime[1] = False
    # even numbers except 2 have been eliminated
    for i in range(3, int(n**0.5+1), 2):
        index = i*2
        while index < n:
            is_prime[index] = False
            index = index+i
    prime = [2]
    for i in range(3, n, 2):
        if is_prime[i]:
            prime.append(i)
    return prime


def is_permutation(b, c):
    b, c = str(b), str(c)
    if len(b) != len(c):
        return False
    b, c = sorted(b), sorted(c)
    for i in range(len(b)):
        if b[i] != c[i]:
            return False
    return True

a = 1487
primes = sieve(10000)
while True:
    a += 2
    b, c = a + 3330, a + 6660
    if a in primes and b in primes and c in primes and is_permutation(a, b) and is_permutation(b, c):
        print(str(a) + str(b) + str(c))
        break