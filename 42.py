from math import sqrt

words = list(map(lambda x: x[1: -1].lower(), open("p042_words.txt", 'r').read().split(",")))
ALPHABET = list("abcdefghijklmnopqrstuvwxyz")
num_triangles = 0
for word in words:
    k = sum([ALPHABET.index(x) + 1 for x in word])
    test = (-1 + sqrt(1 + 8*k))/2
    if int(test) == test:
        num_triangles += 1

print(num_triangles)
