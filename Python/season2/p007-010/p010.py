# coding: UTF-8
"""
　2018.4.6
　三角形の状態判定
"""

def triangle(a,b,c):
    if a+b < c or b+c < a or c+a < b:
      return "非三角形"
    elif a==b==c:
      return "正三角形"
    elif (a==b) or (b==c) or (c==a):
      return "二等辺三角形"
    else:
      return "三角形"

print( triangle(1,1,1) )
print( triangle(2,1,2) )
print( triangle(3,4,5) )
print( triangle(1,1,3) )