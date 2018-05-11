# coding: UTF-8
"""
　2018.5.2
　CSVファイルの整形
"""

import csv

years = []
july_temps = []

# データの読み込み
with open('tokyo-temps.csv', 'r', encoding='sjis') as f:
    n = 0
    year = 1875
    rdr = csv.reader(f)
    for row in rdr:
        n += 1
        # 7月の気温
        if n>=48 and (n-48)%12 == 0:
            years.append(year)
            july_temps.append(float(row[1]))
            year += 1

# 整形データの書き込み
with open('out.csv', 'w') as f:
    wtr = csv.writer(f, lineterminator='\n')
    for i in range(0, len(years)):
        wtr.writerow([years[i], july_temps[i]])
