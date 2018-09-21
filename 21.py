N = 10000
l = [i for i in range(0, N+1)]

def sum_div(m):
  sm = 1
  if m%2 == 0:
    for i in range(2, m//2 +1):
      if m%i == 0:
        sm += i
  else:
    for i in range(3, m//2 +1):
      if m%i == 0:
        sm += i
  return sm

l = [sum_div(i) for i in l]
print(l[:10])
amical = 0
for i in range(1, N):
  m = l[i]
  if m >= N :
    continue
  else :
    if l[m] == i and i != m:
      amical += i


print(amical)