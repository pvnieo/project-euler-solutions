
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

factorial_cache = {i: factorial(i) for i in range(10)}


def is_digit_factorial(n):
    if n in [1, 2]:
        return False
    return n == sum(map(lambda x: factorial_cache[int(x)], list(str(n))))

print(sum((i for i in range(2, 8 * factorial_cache[9] + 1) if is_digit_factorial(i))))
