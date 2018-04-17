# coding: UTF-8
"""
　2018.4.17
　引数で与えられる2つの整数間（両整数を含む）の整数の総和
"""

def sum_n(x,y):
    n = 0
    for i in range(x, y+1, 1):
        n += i
        print(i, n)
    return n

print(sum_n(1,3))
print(sum_n(9,1453))