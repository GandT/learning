import random

def random_ints(a, n):
    i = 0
    l = []
    while i < n:
        l += [random.randrange(0, a)]
        i += 1
    return l

print random_ints(10000000,10)
