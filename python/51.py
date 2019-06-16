import numpy as np
from itertools import combinations_with_replacement, product
from collections import defaultdict

# it took me a long time, the code is not clean and optimized


def is_prime_basic(x):
    if x <= 1:
        return False
    elif x <= 3:
        return True
    elif x % 2 == 0 or x % 3 == 0:
        return False
    i = 5
    while i ** 2 <= x:
        if x % i == 0 or x % (i+2) == 0:
            return False
        i += 6
    return True


def is_sub_in_l(a, b):
    """Verify if elements of a in b and b - a is composed from the same digit"""
    b = list(map(int, str(b)))
    for x in a:
        try:
            b.remove(x)
        except ValueError:
            return False
    if len(set(b)) == 1:
        return True
    return False


def get_unique(l):
    tr = []
    for x in l:
        if x not in tr:
            tr.append(x)
    return tr


def get_fixed(temp, x):
    """Return list of list of primes that have the digits in x in the same position"""
    temp_s = list(map(lambda p: list(str(p)), temp))
    x_s = list(map(str, x))
    dic_index = defaultdict(list)
    for i, p in enumerate(temp_s):
        inds = {}
        for j, s in enumerate(x_s):
            indices = [k for k, x in enumerate(p) if x == s]
            inds[j] = indices
        inds = list(product(*inds.values()))
        for ind in inds:
            if len(set(ind)) == len(x):
                dic_index[ind].append(temp[i])
    if len(set(x)) != len(x):
        unique, counts = np.unique(x, return_counts=True)
        d = dict(zip(unique, counts))
        for item, count in d.items():
            if count > 1:
                indices = [a for a, b in enumerate(x) if b == item]
                keys = list(dic_index.keys())
                truth = [tuple([idx[n] for n in indices]) for idx in keys]
                truth = [tuple([set(truth[i]), set(k) - set(truth[i])]) for i, k in enumerate(keys)]
                # print(truth)
                unique = get_unique(truth)
                for i, u in enumerate(unique):
                    truth = [i if t == u else t for t in truth]
                for i in range(len(unique)):
                    trc = truth.copy()
                    save = truth.index(i)
                    trc.remove(i)
                    for j in range(truth.count(i) - 1):
                        ii = trc.index(i)
                        trc.remove(i)
                        dic_index[keys[save]] += dic_index[keys[ii]]
                    dic_index[keys[save]] = list(set(dic_index[keys[save]]))
    return dic_index.values()


def is_family(primes, n, len_min=7):
    """search in the list of primes_composition if there is a family of numbers that has n digit in common"""
    to_return = []
    for x in combinations_with_replacement(range(10), n):
        temp = []
        for i, prime in enumerate(primes):
            if is_sub_in_l(x, prime):
                temp.append(prime)
        if len(temp) >= len_min:
            temp = get_fixed(temp, x)
            for list_primes in temp:
                if len(list_primes) >= len_min:
                    to_return.append((x, tuple(list_primes)))
    return to_return

primes = []
for p in range(100001, 999999, 2):
    if is_prime_basic(p):
        unique, counts = np.unique(list(str(p)), return_counts=True)
        d = {}
        for i, x in enumerate(unique):
            d[int(x)] = counts[i]
        primes.append(p)

for i in range(3, len(str(primes[0])) - 1):
    tr = is_family(primes, i, len_min=8)
    if len(tr) > 0:
        print(tr)
        break
