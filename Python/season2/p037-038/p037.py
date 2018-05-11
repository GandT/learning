# coding: UTF-8
"""
　2018.5.2
　フィボナッチ数列のダンプ
"""

import json

def fib(n):
    if (n == 0):
        return 0
    elif (n == 1):
        return 1
    else:
        return fib(n-1)+fib(n-2)

jsi = [{'n': n, 'fib' : fib(n)} for n in range(0,10)]
with open("fib.json", "w") as f:
    json.dump(jsi, f)
with open("fib.json", "r") as f:
    jso = json.load(f)
print(jsi == jso)