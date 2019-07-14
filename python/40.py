
d = ""
i, p = 1, 1
needed = [1, 10, 100, 1000, 10000, 100000, 1000000]

while len(d) < 1000000:
    d += str(i)
    i += 1

for x in needed:
    p *= int(d[x - 1])

print(p)
