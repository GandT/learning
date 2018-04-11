# coding: UTF-8
"""
　2018.4.6
　二次関数の値を求める
"""

def quadratic(a, b, c, x):
  return a*x**x + b*x + c


print( "ax^2 + bx + c = ?" )

a = 1
b = 2
c = 3
x = 10
print( "a:{} b:{} c:{} x:{}".format(a, b, c, x) )
print( "{}".format(quadratic(a, b, c, x)) )

a = 3
b = 4
c = 1
x = 5
print( "a:{} b:{} c:{} x:{}".format(a, b, c, x) )
print( "{}".format(quadratic(a, b, c, x)) )