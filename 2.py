M = 4000000

fib1, fib2, fib = 1, 2, 3
s = 2
while fib < M:
    if fib % 2 == 0:
        s += fib
    fib1 = fib2
    fib2 = fib
    fib = fib1 + fib2

print(s)
