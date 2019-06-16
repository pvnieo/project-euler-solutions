

def digital_sum(n):
    return sum(map(int, list(str(n))))

if __name__ == "__main__":
    a, b = 100, 100
    maximum = 0
    for i in range(1, a):
        for j in range(1, b):
            M = digital_sum(i ** j)
            if M > maximum:
                maximum = M

    print(maximum)
