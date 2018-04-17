# coding: UTF-8
"""
　2018.4.17
　文字列リストの文字数カウントと大文字化
"""

def length_and_upper(string_list):
  return [ [len(word), word.upper()] for word in string_list ]

print(length_and_upper(["x", "xyz", "qawsedrftgyhyjukljkohgjukgkjuhjgj"]))