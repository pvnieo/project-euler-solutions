
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


def rotations(digits):
    l = []
    for i in range(len(digits) - 1):
        digits = [digits[-1]] + digits[:-1]
        l.append(int("".join(map(str, digits))))
    return l


def is_circular_prime(p):
    digits = list(map(int, str(p)))
    if sum([1 if x % 2 == 0 else 0 for x in digits]) != 0 and p != 2:
        return False
    combinations = rotations(digits)
    for x in combinations:
        if not is_prime_basic(x):
            return False
    return True


c_p = 0
for i in range(1000000):
    print(i, "\r", end="")
    if is_prime_basic(i) and is_circular_prime(i):
            c_p += 1

print()
print(c_p)