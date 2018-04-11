# coding: UTF-8
"""
　2018.4.6
　二次方程式 ax^2+bx+c=0 に関して解求める
"""

import math


def det(a, b, c):
  return b*b - 4*a*c

def solution1(a, b, c):
  return (-b + math.sqrt( det(a, b, c) )) / 2*a

def solution2(a, b, c):
  return (-b -  math.sqrt( det(a, b, c) )) / 2*a

"""
# math.sqrtは複素数は扱えない
a = 3
b = 2
c = 1
print( "a={}  b={}  c={}".format(a, b, c) )
print( "x1={}".format(solution1(a, b, c)) )
print( "x2={}".format(solution2(a, b, c)) )
"""

a = 1
b = 2
c = 1
print( "a={}  b={}  c={}".format(a, b, c) )
print( "x1={}".format(solution1(a, b, c)) )
print( "x2={}".format(solution2(a, b, c)) )

a = 1
b = 4
c = 1
print( "a={}  b={}  c={}".format(a, b, c) )
print( "x1={}".format(solution1(a, b, c)) )
print( "x2={}".format(solution2(a, b, c)) )
