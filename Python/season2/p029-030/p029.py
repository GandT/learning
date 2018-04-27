# coding: UTF-8
"""
　2018.4.27
　再帰的マージソートの準備
"""

# 統合部分
def merge(left, right):
  if len(left)==0 or len(right)==0:
    return left + right
  else:
    if left[0] < right[0]:
      return [left[0]] + merge(left[1:], right)
    else:
      return [right[0]] + merge(left, right[1:])
    
print(merge([1,3,5], [2,9,11]))