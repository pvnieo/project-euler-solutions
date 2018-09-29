
from functools import reduce

n = str(2**1000)
print(reduce(lambda x,y: int(x) + int(y), n))