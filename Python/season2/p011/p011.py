# coding: UTF-8
"""
　2018.4.11
　:の前後文字列を入れ替え
"""

def swap_string(st):
  # :が1つ以外の個数ある場合はエラー
  if st.count(":") != 1:
    print(st.count(":"))
    return None
  
  # 分割・再合成して返す
  s = st.split(":")
  print(s)
  return s[1] + ":" + s[0]

print( swap_string("Latin:America") )
print( swap_string("Java:Script") )
print( swap_string("インド:ネシア") )