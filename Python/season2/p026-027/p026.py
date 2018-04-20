# coding: UTF-8
"""
　2018.4.20
　ソート済み配列の線形探索
"""

def list_search(ilist, iitem):
    seq = 0
    found = False
    while ilist[seq] <= iitem:
        if ilist[seq] == iitem:
            found = True
        else:
            seq += 1
    return found

testlist = [-20, -7, 0, 1, 2, 8, 13, 17, 19, 32, 42, 124]
print(list_search(testlist, 3))
print(list_search(testlist, 13))
