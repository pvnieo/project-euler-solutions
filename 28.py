
def create_odd_spiral(spiral):
    spiral_dim = len(spiral[0])
    last_number = spiral[0][-1]
    last_number += 1
    for i in range(spiral_dim):
        spiral[0 + i] = spiral[0 + i] + [last_number]
        last_number += 1
    spiral.append([])
    for i in range(spiral_dim + 2):
        spiral[-1] = [last_number] + spiral[-1]
        last_number += 1
    for i in range(spiral_dim):
        spiral[-2 - i] = [last_number] + spiral[-2 - i]
        last_number += 1
    spiral = [[]] + spiral
    for i in range(spiral_dim + 2):
        spiral[0] = spiral[0] + [last_number]
        last_number += 1

    return spiral

spiral = [[1]]
for i in range(1001 // 2):
    spiral = create_odd_spiral(spiral)

s = 0
s += sum(spiral[i][i] for i in range(len(spiral)))
s += sum(spiral[i][-1-i] for i in range(len(spiral)))
s -= 1

print(s)

