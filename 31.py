from itertools import combinations_with_replacement


coins = [1, 2, 5, 10, 20, 50, 100, 200]
ways = []
# 200a + 100b + 50c + 20d + 10e + 5f + 2g + h == 200
# Code to be rewritten

for a in range(2):
    r = (200 - 200*a) // 100 + 1
    for b in range(r):
        r = (200 - 200*a - 100*b) // 50 + 1
        for c in range(r):
            r = (200 - 200*a - 100*b - 50*c) // 20 + 1
            for d in range(r):
                r = (200 - 200*a - 100*b - 50*c - 20*d) // 10 + 1
                for e in range(r):
                    r = (200 - 200*a - 100*b - 50*c - 20*d - 10*e) // 5 + 1
                    for f in range(r):
                        r = (200 - 200*a - 100*b - 50*c - 20*d - 10*e - 5*f) // 2 + 1
                        for g in range(r):
                            r = (200 - 200*a - 100*b - 50*c - 20*d - 10*e - 5*f - 2*g) + 1
                            for h in range(r):
                                if 200*a + 100*b + 50*c + 20*d + 10*e + 5*f + 2*g + h == 200:
                                    ways.append((a, b, c, d, e, f, g, h))


ways = set(ways)
print(len(ways))
