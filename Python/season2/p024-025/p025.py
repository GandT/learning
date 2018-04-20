# coding: UTF-8
"""
　2018.4.20
　イテレータ関数
"""

def number_generator(x):
    if (x%2):
        return 3*x+1
    else:
        return x//2

def number_generator_generator():
  yield number_generator(1)
  yield number_generator(2)
  yield number_generator(3)
  yield number_generator(4)
  yield number_generator(5)
  
for num in number_generator_generator():
  print(num)