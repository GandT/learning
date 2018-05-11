# coding: UTF-8
"""
　2018.5.2
　Colaboratoryファイル入出力
"""

# アップロード
from google.colab import files
uploaded = files.upload()

# ファイル入力
with open("input.csv", 'r') as f:
    print(f.read())

# ファイル出力
with open("output.txt", "w") as f:
    f.write("Nyanhello\nworld\n")

# 確認
f = open('output.txt', 'r')
print(f.read())

# ダウンロード
from google.colab import files
files.download('output.txt')