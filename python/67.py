paths = list([list(map(int, st.split())) for st in open("67.txt").readlines()])
for i in range(len(paths)-2, -1, -1):
    for j in range(len(paths[i])):
        paths[i][j] += max(paths[i+1][j], paths[i+1][j+1])
print(paths[0][0])
