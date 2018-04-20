# coding: UTF-8
"""
　2018.4.18
　辞書型可変長引数で受け取ったデータの整理
"""


hash_list = {
    '分布①': ['Law'], 
    '分布②': ['Eco'], 
    '分布③': ['Lit','Edu','Lib'], 
    '分布④': ['Sci','Eng'], 
    '分布⑤': ['Agr','Pha'],
    '分布⑥': ['Med']
}

def hjoint(**hash):
    res = ""
    for value in hash.values():
        for text in value:
            res += (text.upper() + ", ")
    return res[:-2] + "."


print( hjoint(**hash_list) )

