
def is_pal(x):
    for i in range(len(x) // 2):
        if x[i] != x[-1 - i]:
            return False
    return True
M = 0
for i in range(999, 900, -1):
    for j in range(999, 900, -1):
        if is_pal(str(i * j)):
            if i * j > M:
                M = i * j

print(M)