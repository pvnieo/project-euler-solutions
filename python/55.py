def is_pal(x):
    for i in range(len(x) // 2):
        if x[i] != x[-1 - i]:
            return False
    return True


def is_lychrel(n):
    n = str(n)
    i = 0
    while i <= 50:
        n = str(int(n) + int(n[::-1]))
        if is_pal(n):
            return False
        i += 1
    return True


print(sum([1 for i in range(1, 10001) if is_lychrel(i)]))
