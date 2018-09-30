
def is_abundant(n):
  s = 0
  for i in range(1, n // 2 + 1):
    if n % i == 0:
      s += i
  if s > n :
    return True
  else:
    return False


def is_sum_abundant(n, list_abundant):
  for i in list_abundant[::-1]:
    if i < n:
      return False
    elif n == i:
      return True
  return False


th_max = 28123
s = 0
abundants = []
for i in range(1, th_max):
  print(i, "\r", end="")
  if is_abundant(i):
    abundants.append(i)
  dr = False
  for x in abundants:
    if is_sum_abundant((i - x), abundants):
      dr = True
      break
  if not dr:
    s += i

print(s)