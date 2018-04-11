# coding: UTF-8
"""
　2018.4.6
　二次方程式 ax^2+bx+c=0 に関して判別式を求める
"""

def det(a, b, c):
  return b*b - 4*a*c

print( "ax^2 + bx + c = 0" )

a = 3
b = 2
c = 1
print( "a={}  b={}  c={}".format(a, b, c) )
print( "判別式 D={}".format(det(a, b, c)) )

a = 1
b = 2
c = 1
print( "a={}  b={}  c={}".format(a, b, c) )
print( "判別式 D={}".format(det(a, b, c)) )

a = 1
b = 4
c = 1
print( "a={}  b={}  c={}".format(a, b, c) )
print( "判別式 D={}".format(det(a, b, c)) )
