
def it_is_abundant(n):
  k = 0
  for i in range(n//2 + 1, 0, -1):
    if n % i == 0:
      k += i
      if k > n :
        return True
  else :
    return False
dictn = {}
dictn[12] = set([12])
for x in range(13,28124):

  if it_is_abundant(x):
    print("ab{}".format(x))
    dictn[x] = dictn[x-1] | {x}
  else:
    print("Nab{}".format(x))
    dictn[x] = dictn[x-1].copy()
count = 0
print("Begin search ...")
def is_sum(num, l):
  for i in range(len(l)):
    for j in range(i, len(l)):
      if i+j == num:
        return True
  return False

for i in range(28124):
  l = []
  for j in abundant:
    if j <= i:
      l.append(j)
    else :
      break
  if not is_sum(i,l):
    count += i

print(count)