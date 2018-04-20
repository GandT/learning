# coding: UTF-8
"""
　2018.4.20
　リストからイテレータを作成し一つずつ表示
"""

slist = ['LAW', 'ECO', 'LIT', 'EDU', 'LIB', 'SCI', 'ENG', 'AGR', 'PHA', 'MED']
iterobj = ( s[0]+s[1:].lower()  for s in slist )

for i in iterobj:
  print(i)
