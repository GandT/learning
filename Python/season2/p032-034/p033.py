# coding: UTF-8
"""
　2018.5.2
　単語リストの作成
"""

import re
a = []
with open('text-sample.txt', 'r') as f:
    # 行ごとに解析
    for line in f:
        words = re.split('[^a-zA-Z]+', line)

        # 単語が適格であればリストに追加
        for word in words:
            if word != '':
                a.append(word.lower())

print(sorted(list(set(a))))
