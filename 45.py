from math import sqrt


def is_penta(n):
    t = (1 + sqrt(1 + 24 * n)) / 6
    if int(t) == t:
        return True
    return False


def is_hexa(n):
    t = (1 + sqrt(1 + 8*n)) / 4
    if int(t) == t:
        return True
    return False

assert is_penta(40755)
assert is_hexa(40755)
print("ok")

i = 286

while True:
    t = (i * (i+1)) / 2
    if is_penta(t) and is_hexa(t):
        print(t)
        break
    i += 1
