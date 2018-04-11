# coding: UTF-8
"""
　2018.4.6
　三角形の二等辺三角形判定
"""

def isosceles(a, b, c):
  return (a==b) or (b==c) or (c==a)

a, b, c = 1, 2, 3
print( "a={} b={} c={} : {}".format(a, b, c, isosceles(a,b,c)) )

a, b, c = 1, 1, 3
print( "a={} b={} c={} : {}".format(a, b, c, isosceles(a,b,c)) )

a, b, c = 1, 2, 1
print( "a={} b={} c={} : {}".format(a, b, c, isosceles(a,b,c)) )

a, b, c = 15543.1, 15543.1, 3
print( "a={} b={} c={} : {}".format(a, b, c, isosceles(a,b,c)) )

a, b, c = 15543.12, 15543.12, 15543.12
print( "a={} b={} c={} : {}".format(a, b, c, isosceles(a,b,c)) )

a, b, c = 1234567.8901234567891, 1234567.8901234567892, 1234567.8901234567893
print( "a={} b={} c={} : {}".format(a, b, c, isosceles(a,b,c)) )