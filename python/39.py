
def num_solution(p):
    s = 0
    for a in range(1, p//2):
        b = (p**2 - 2*a*p) / (2*p - 2*a)
        if int(b) == b:
            s += 1
    return s // 2


assert num_solution(120) == 3

M, p = 0, 0

for i in range(1, 1001):
    s = num_solution(i)
    if s > M:
        M, p = s, i

print(p)
