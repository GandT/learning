# coding: UTF-8
"""
　2018.4.17
　while文の練習
"""

from time import sleep

i = 0
while i < 10:
    print ("こん！")
    sleep(0.1)
    i += 1
else:
    print("おわり～")
    if i != 10:
        print("error")
    else:
        pass