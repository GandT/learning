# coding: UTF-8
"""
　2018.4.20
　再帰によるソート済み配列の線形探索
"""

def list_search(ilist, iitem):
    if ilist[0] == iitem:
        return True
    else:
        if len(ilist) == 1:
            return False
        else:
            return list_search(ilist[1:], iitem)

t = [-20, -7, 0, 1, 2, 8, 13, 17, 19, 32, 42, 124]
print(list_search(t, 3))
print(list_search(t, 13))
