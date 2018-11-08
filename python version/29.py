
all_powers = []
A, B = 100, 100
for a in range(2, A + 1):
    for b in range(2, B + 1):
        print("a: ", a, "b: ", b, "\r", end="")
        all_powers.append(a ** b)

print()
print(len(set(all_powers)))
