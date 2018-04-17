# coding: UTF-8
"""
　2018.4.13
　条件分岐の整理
"""

def check_num_size(x):
    if 2 <= x < 3:
        print ("2 以上 3 未満")
    elif 1 <= x < 2:
        print ("1 以上 2 未満")
    elif x < 1:
        print ("1 未満")
    else:
        print("3 以上")

check_num_size(-1)
check_num_size(10)