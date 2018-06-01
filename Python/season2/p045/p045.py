# coding: UTF-8
"""
　2018.5.25
　NumPy演習
"""

import numpy as np
import math

# n次元ユークリッド空間におけるコサイン類似度
def cos_sim(X,Y):
    x = np.array(X)
    y = np.array(Y)

    numer = np.sum(x*y)
    denom = math.sqrt(np.sum(x*x)) * math.sqrt(np.sum(y*y))

    return numer / denom

print(cos_sim([0,1,2,3], [3,2,1,0]))