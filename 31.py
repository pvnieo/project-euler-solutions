from itertools import combinations_with_replacement


coins = [1, 2, 5, 10, 20, 50, 100, 200]
ways = [(200), (100, 100)]

for i in range(1, 50):
    print(i, "\r", end="")
    for x in set(sorted(list(combinations_with_replacement(coins[:5], i)))):
        s = sum(x)
        if s == 50:
            ways.append(tuple(sorted(x)))


print()
ways = set(ways)
print(len(ways))
