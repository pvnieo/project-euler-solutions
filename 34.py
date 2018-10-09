
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

factorial_cache = {i: factorial(i) for i in range(10)}

def is_digit_factorial(n):
    if n in [1, 2]:
        return False
    l = list(str(n))
    s = sum(list(map(lambda x: factorial_cache[int(x)], l)))
    if s == n:
        return True
    else:
        return False

s = 0       
for i in range(8 * factorial_cache[9] + 1):
    print(i, "\r", end="")
    if is_digit_factorial(i):
        s += i

print()
print(s)