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

i = 286

while True:
    t = (i * (i+1)) / 2
    if is_penta(t) and is_hexa(t):
        print(t)
        break
    i += 1
