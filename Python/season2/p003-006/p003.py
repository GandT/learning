# coding: UTF-8
"""
　2018.4.6
　フィート・インチをセンチメートルに変換
"""

def feet_to_cm(f, i):
  return (f*12 + i) * 30.48

print( "{} feet {} inch = {} cm".format(1, 0, feet_to_cm(1,0)) )
print( "{} feet {} inch = {} cm".format(1, 1, feet_to_cm(1,1)) )
print( "{} feet {} inch = {} cm".format(2, 0, feet_to_cm(2,0)) )
print( "{} feet {} inch = {} cm".format(2, 1, feet_to_cm(2,1)) )
