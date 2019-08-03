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


def is_prime(x):
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


def is_eight_family(p, d):
    count = 0
    for i in '0123456789':
        n = int(p.replace(d, i))
        if is_prime(n) and n > 100000:
            count += 1
    return count == 8


if __name__ == '__main__':
    for prime in sieve(1000000):
        if prime > 100000:
            s = str(prime)
            if (s.count('0') == 3 and is_eight_family(s, '0')) or\
               (s.count('1') == 3 and is_eight_family(s, '1')) or \
               (s.count('2') == 3 and is_eight_family(s, '2')):
                break
    print(prime)
