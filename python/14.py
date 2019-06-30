
def next_collatz(n):
    if n % 2 == 0:
        return n // 2
    else:
        return 3 * n + 1


def collatz_length(n):
    s = 1
    while n != 1:
        n = next_collatz(n)
        s += 1
    return s

M = 1000000
max_length, arg = 1, 1
for i in range(1, M+1):
    print(i, "\r", end="")
    length = collatz_length(i)
    if length > max_length:
        max_length = length
        arg = i

print()
print(arg)
