# coding: UTF-8
"""
　2018.4.13
　遺伝子配列のエンコード
"""

def atgc_encode(s):
    # 個数を数えてハッシュ化
    a, t, g, c = s.count("A"), s.count("T"), s.count("G"), s.count("C")
    atgc = {a: "A", t: "T", g: "G", c:"C"}

    # ソート
    atgc = sorted(atgc.items())
    
    # 変換テーブルの作成
    encoder = {atgc[0][1]: "4", atgc[1][1]: "3", atgc[2][1]: "2", atgc[3][1]: "1"}

    result = ""
    for c in s:
        result += encoder[c]

    return result

print(atgc_encode("AAGCCCCATGGTAA"))
print(atgc_encode("AAAATTTTGGCCCCCAAAAA"))