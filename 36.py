

def is_pal(s):
    for i in range(len(s) // 2):
        if s[i] != s[-1 - i]:
            return False
    return True

s = 0

for i in range(1000000):
    print(i, "\r", end="")
    if is_pal(str(i)) and is_pal(bin(i)[2:]):
        s += i

print()
print(s)