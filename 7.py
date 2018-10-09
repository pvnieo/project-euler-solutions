
def is_prime_basic(x):
    if x <= 1:
        return False
    elif x <= 3:
        return True
    elif x % 2 == 0 or x % 3 == 0:
        return False
    i = 5
    while i ** 2 <= x:
        if x % i == 0 or x % (i+2) == 0:
            return False
        i += 6
    return True

counter, i = 0, 2
max = 10001
while counter < max:
    if is_prime_basic(i):
        counter += 1
        print(counter, "\r", end="")
    i += 1

print()
print(i-1)
