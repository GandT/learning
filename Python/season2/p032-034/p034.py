# coding: UTF-8
"""
　2018.5.2
　テキストファイルの行数カウント
"""

def count_line(name):
    counter = 0

    with open(name, 'r') as f:
        for line in f:
            counter += 1

    return counter

print(count_line('text-sample.txt'))