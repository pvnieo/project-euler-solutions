

def lattice(n, m):
    lat = [[1 for i in range(m)] for i in range(n)]
    for i in range(n-2, -1, -1):
        for j in range(m-2, -1, -1):
            lat[i][j] = lat[i+1][j] + lat[i][j+1]
    return lat[0][0]

print(lattice(21, 21))