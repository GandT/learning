# coding: UTF-8
"""
　2018.5.25
　pandas演習
"""

import pandas as pd

iris_d = pd.read_csv("iris.csv")
print(iris_d[(iris_d["species"]) == "setosa"]["sepal_length"].max())