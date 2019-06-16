from itertools import permutations


def check_property(n):
    if (n[3] % 2 != 0) or (n[5] not in [0, 5]) or (n[0] == 0):
        return False
    tests = [2, 3, 5, 7, 11, 13, 17]
    for i, x in enumerate(tests):
        a = int("".join(map(str, n[i+1: i+4])))
        if a % x != 0:
            return False
    return True

assert check_property((1, 4, 0, 6, 3, 5, 7, 2, 8, 9))
assert not check_property((0, 4, 0, 6, 3, 5, 7, 2, 8, 9))

pandigitals = permutations(range(10))
s = 0
for num in pandigitals:
    if check_property(num):
        s += int("".join(map(str, num)))

print(s)
