# coding: UTF-8
"""
　2018.4.13
　指定された月の日数を返す（閏年を考慮）
"""

def day_of_month(year, month):
    # 不正な月が指定された場合Noneを返す
    if  type(year) != int  or  type(month) != int  or  not(1 <= month <= 12):
        return None

    # 2月を除くハッシュテーブル（辞書）の作成
    table = {
        1: 31,  2: -1,  3: 31,  4: 30,  5: 31,  6: 30,
        7: 31,  8: 31,  9: 30, 10: 31, 11: 30, 12: 31
    }

    # 年から2月の値を確定
    table[2] = 29 if (year % 400 == 0) or ((year % 100 != 0) and (year % 4 == 0)) else 28

    # テーブルから結果を返す
    return table[month]

print( day_of_month(   1, 1) )
print( day_of_month(87346894238473687461, 3) )
print( day_of_month(1000,13) )
print( day_of_month(2001, 2) )
print( day_of_month(2004, 2) )
print( day_of_month(2100, 2) )
print( day_of_month(2000, 2) )
print( day_of_month(100.4, 3) )
print( day_of_month(1999, "アポカリプス") )

