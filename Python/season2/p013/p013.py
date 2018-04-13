# coding: UTF-8
"""
　2018.4.12
　辞書（Ruby: Hash）の練習
"""


dic1 = {'one':1, 'two':3, 'three':3, 'four':4, 'five':10, 'six':6, 'seven':7}

# 不適切なfiveの排除
print( dic1.pop("five") )
print( dic1 )

# 追加
dic1["eight"] = 8
dic1["nine"] = 9

print(dic1)