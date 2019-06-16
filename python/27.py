
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


def len_consectuve_prime(a, b):
    s = 0
    while True:
        if is_prime_basic(s**2 + a * s + b):
            s += 1
        else: 
            break
    return s-1


M, p = 0, 1
for a in range(-999, 1000):
    for b in range(-999, 1000):
        print("a: ", a, "b: ", b, "\r", end="")
        length = len_consectuve_prime(a, b)
        if length > M:
            M = length
            p = a * b

print()
print(p)
