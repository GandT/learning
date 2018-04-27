# coding: UTF-8
"""
　2018.4.20
　バブルソートの前準備
"""

def pre_bubble(ln):
  for i in range(len(ln) - 1):
    if(ln[i] > ln[i+1]):
      temp = ln[i+1]
      ln[i+1] = ln[i]
      ln[i] = temp
  
  return ln # 参照渡しなのでlnはそのまま変化


a = [10,3,6,4,7,8,2,9,5,1]
print(a)
print(pre_bubble(a))
print(pre_bubble(a))
print(pre_bubble(a))