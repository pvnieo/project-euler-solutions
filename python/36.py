

def is_pal(s):
    for i in range(len(s) // 2):
        if s[i] != s[-1 - i]:
            return False
    return True

print(sum((i for i in range(1000000) if is_pal(str(i)) and is_pal(bin(i)[2:]))))
