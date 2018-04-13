# coding: UTF-8
"""
　2018.4.12
　リストの中間要素を与える
"""


def list_cut(ln, x, y):
    # lnがlistでない場合
    if type(ln) != list:
        return None
    # xまたはyがない場合
    if (x not in ln) or (y not in ln):
        return None

    # xとyのindexを取得
    indexs = [ln.index(x), ln.index(y)]
    indexs.sort() # 本当は [ln.index(x), ln.index(y)].sort() とやりたいがなぜかダメらしい

    # 部分を返す
    return ln[ indexs[0] : indexs[1]+1 ]


ln = [9,2,4,5,6,1,8,7,3]
print( ln )
print( list_cut(ln, 2, 3) )
print( list_cut(ln, 7, 4) )
print( list_cut(ln, 10, 10) )