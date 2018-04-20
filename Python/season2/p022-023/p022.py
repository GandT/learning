# coding: UTF-8
"""
　2018.4.18
　可変長引数整数列の最大値・平均値・分散
"""

def list_max(*numlist):
    return sorted(numlist)[-1]


def list_average(*numlist):
    l = len(numlist)
    s = 0
    for i in numlist:
        s += i
    return s / l


def list_var(*numlist):
    l = len(numlist)
    s = 0
    e = list_average(*numlist)
    for i in numlist:
        s += (i - e)**2
    return s / l


print(list_max(9,2,3,2,7,125,2,-3489))
print(list_average(9,2,3,2,7,125,2,-3489))
print(list_var(9,2,3,2,7,125,2,-3489))