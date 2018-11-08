r = 1
count = 0

for i in range(1, 100):
    r = r * i
for i in str(r):
    count += int(i)
print(count)
