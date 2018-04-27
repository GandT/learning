# coding: UTF-8
"""
　2018.4.27
　再帰的マージソート
"""
def merge(left, right):
  if len(left)==0 or len(right)==0:
    return left + right
  else:
    if left[0] < right[0]:
      return [left[0]] + merge(left[1:], right)
    else:
      return [right[0]] + merge(left, right[1:])
    
def merge_sort(L):
  if len(L) <= 1:
    return L
  else:
    length = len(L)//2
    l = merge_sort(L[:length])
    r = merge_sort(L[length:])
    return merge(l, r)

print(merge_sort([1,7,4,5,9,3,0,6,2,8]))