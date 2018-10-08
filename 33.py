from fractions import Fraction

# The ugliest code I've ever written

def is_digit_cancelling(i, j):
    if i % 10 == 0 and j % 10 == 0:
        return False
    elif i < 10 or j < 10:
        return False
    elif set(str(i)) & set(str(j)) == set(""):
        return False
    else:
        d = i/j
        i, j = str(i), str(j)
        for a in set(i) & set(j):
            i1 = i[:i.index(a)] + i[i.index(a)+1:]
            j1 = j[:j.index(a)] + j[j.index(a)+1:]
            if j1 == '0':
                return False
            elif d == (int(i1) / int(j1)):
                return True
        return False

l = []
for i in range(1, 100):
    for j in range(i+1, 100):
        if is_digit_cancelling(i, j):
            l.append((i,j))

p = (1,1)
for t in l:
    a, b = t
    p = (p[0]*a, p[1]*b)

print(Fraction(p[0], p[1]).denominator)
