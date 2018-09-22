N = 600851475143 + 1
primes = [2,3,5,7]
for i in range(10, N):
    for x in primes:
        if i%x == 0:
            primes.append(i)
            break
for i in range(len(primes), -1):
    if (N-1) % i == 0:
        print(i)
        break