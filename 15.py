
def lattice(n,m):
    # if n == 1 :
    #     return 1
    # elif n == 13 and m == 13:
    #     return 2704156
    # else:
    #     total = 0
    #     for i in range(1, m+1):
    #         total += lattice(n-1, m-i+1)
    #     return total
    lat = [[1 for i in range(m)] for i in range(n)]
    for i in range(n-2,-1,-1):
        for j in range(m-2,-1, -1):
            lat[i][j] = lat[i+1][j] +lat[i][j+1]



    return lat[0][0]

print(lattice(21,21))