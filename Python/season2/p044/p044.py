# coding: UTF-8
"""
　2018.5.25
　実行時属性作成
"""

import utas
import json

def utcourses():
    # 結果を返すリスト
    result_list = []

    # カタログからオブジェクトを生成
    with open("catalog-2018.json", "r") as fp:
        jin = json.load(fp)

        # クラス化して配列に要素追加
        for info in jin:
            result_list.append(utas.UTCourse(info))

    return result_list

def filter_ccc(code, utcs_object_list): # どうでもいいんですが普通これはUTCoursesクラスのメンバ関数では（配列要求してるので怪しさはある）
    answer = []

    # 線形探索
    for obj in utcs_object_list:
        if hasattr(obj, "Common_Course_Code"):
           if obj.Common_Course_Code == code:
                answer.append(obj)

    return answer

# テスト
data = filter_ccc("FEN-MP4d01L1", utcourses())
print(data[0].title_j)