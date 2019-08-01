def is_multi_has_same_digits(x):
    base = sorted(list(map(int, str(x))))
    for i in range(2, 7):
        if base != sorted(list(map(int, str(x * i)))):
            return False
    return True

x = 10

while(not is_multi_has_same_digits(x)):
    x += 1

print(x)