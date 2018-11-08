
pandigitals = []
for i in range(1, 9999):
    for j in range(1, 9999):
        print('i: ', i, 'j: ', j, '\r', end="")
        p = str(i * j)
        t = p + str(i) + str(j)
        if len(t) > 9:
            break
        elif len(t) == 9 and sorted(t) == ['1', '2', '3', '4', '5', '6', '7', '8', '9']:
            pandigitals.append(int(p))

print()
print(set(pandigitals))
print(sum(set(pandigitals)))
