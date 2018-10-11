
def get_cycle(a, b):
    decimal = ""
    if a >= b:
        a = a % b
    restes = []
    while a != 0 and a not in restes:
        restes.append(a)
        a *= 10
        decimal += str(a // b)
        a = a % b
    if a == 0:
        return ""
    else: 
        return decimal[restes.index(a):]


cycle_max, max_len, k = 0, 0, 0

for i in range(1, 1000):
    cycle = get_cycle(1, i)
    length = len(cycle)
    if max_len < length:
        cycle_max, max_len = cycle, length
        k = i

print(k, max_len)
