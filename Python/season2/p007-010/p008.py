# coding: UTF-8
"""
　2018.4.6
　数値 x のシグノイド関数
"""

def sign(x):
  if x > 0:
    return 1
  elif x == 0:
    return 0
  else:
    return -1

a = 1
print("{}\n{}".format(a, sign(a)))
a = -a
print("{}\n{}".format(a, sign(a)))
a = 932894798278727867867834974983267886547386876278346876784368756876278687684730928340
print("{}\n{}".format(a, sign(a)))
a = -52635478712637567325487956782398287643.23847912785236487263790122840939867823674823423798523876427349832794873267832
print("{}\n{}".format(a, sign(a)))
a = 0
print("{}\n{}".format(a, sign(a)))