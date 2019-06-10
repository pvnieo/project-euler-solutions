
def factorial(n):
    global factorials
    try:
        return factorials[n]
    except KeyError:
        p = 1
        for i in range(2, n+1):
            p *= i
        factorials[n] = p
        return p


def combinations(n, r):
    return factorial(n) / (factorial(r) * factorial(n - r))

factorials = {0: 1}

s = 0

for n in range(1, 101):
    for r in range(n+1):
        if combinations(n, r) > 999999:
            s += 1

print(s)
