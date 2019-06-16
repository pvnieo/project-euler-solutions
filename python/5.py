
def is_div_20(x):
    for i in range(2, 21):
        if x % i != 0:
            return False
    return True

i = 1
while True:
    k = 19*17 * i
    print(i, "\r", end="")
    if is_div_20(k):
        print()
        print(k)
        break
    else:
        i += 1
