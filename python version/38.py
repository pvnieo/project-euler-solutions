
def is_pandigital_9(n):
    if len(n) == 9 and set(n) == set('123456789'):
        return True
    return False


def find_pandigital(n):
    t = str(n) + str(2 * n)
    i = 3
    while len(t) <= 9:
        if is_pandigital_9(t):
            return int(t)
        t += str(n * i)
        i += 1
    return False

M = 0

for i in range(10000):
    t = find_pandigital(i)
    if t and t > M:
        M = t

print(M)
