# coding: UTF-8
"""
　2018.4.27
　二分探索
"""

def binary_search(mylist, myitem):
    if len(mylist)==0:  
        return False
    mid = len(mylist)//2

    if mylist[mid]==myitem:
        return True
    else:
        if mylist[mid] < myitem:
            print(mylist[mid+1:])
            return binary_search(mylist[mid+1:], myitem)
        else:
            print(mylist[:mid])
            return binary_search(mylist[:mid], myitem)

list0 = [1,3,4,6,7,9,10,13,15,19,24,35]
print(binary_search(list0,  3))
print(binary_search(list0, 13))
print(list0)
print(binary_search(list0, 23))