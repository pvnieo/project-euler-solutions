
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


def is_truncatable_prime(p):
    digits = list(map(int, str(p)))
    if sum([1 if x % 2 == 0 else 0 for x in digits[1:]]) != 0 and p != 2:
        return False
    elif digits[0] % 2 == 0 and digits[0] != 2:
        return False
    for i in range(len(digits) - 1):
        a, b = int("".join(map(str, digits[: -1 - i]))), int("".join(map(str, digits[i + 1:])))
        if (not is_prime_basic(a)) or (not is_prime_basic(b)):
            return False
    return True

s, count, i = 0, 0, 11

while count < 11:
    print(i, " | ", count, "\r", end="")
    if is_prime_basic(i) and is_truncatable_prime(i):
        count += 1
        s += i
    i += 2

print()
print(s)
