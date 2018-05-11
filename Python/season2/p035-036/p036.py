# coding: UTF-8
"""
　2018.5.2
　CSVファイルのリスト化
"""

import csv

def csv_matrix(name):
    answer = []
    with open(name, 'r') as f:
        rdr = csv.reader(f)
        for row in rdr:
            for cell in row:
                answer.append(int(cell))

    return answer

print(csv_matrix("small.csv"))