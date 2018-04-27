# coding: UTF-8
"""
　2018.4.20
　ユークリッド距離の計算
"""

import math
from functools import reduce

def distance(list1, list2):
  return math.sqrt(reduce(lambda x,y : x+y,  list( map(lambda x,y : (x - y)**2, list1, list2) ) ))

d = distance([1,2,4], [3, 0, 2])
print(d, d**2)