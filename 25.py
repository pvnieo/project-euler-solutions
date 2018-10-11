
fib_n_2, fib_n_1, fib_n, n = 1, 1, 2, 3

while len(str(fib_n)) < 1000:
    fib_n_2 = fib_n_1
    fib_n_1 = fib_n
    fib_n = fib_n_1 + fib_n_2
    n += 1
    print(n, "\r", end="")


print()
print(n)
