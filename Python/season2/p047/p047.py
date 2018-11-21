# coding: UTF-8
"""
　2018.5.25
　ライブラリを利用した情報処理
"""

import csv
import json
import numpy as np
import pandas as pd
import utas

def utcourses():
    with open("catalog-2018.json", "r", encoding="utf-8") as f:
        return [utas.UTCourse(d) for d in json.load(f)] 

def keywords():
    with open('course_keyword_list.csv', 'r',  encoding="utf-8") as csvf:
        return [row[0] for row in csv.reader(csvf)]

def find_course(title, lecturer, utcs):
    # 入力:
        # 第1引数:授業名の文字列, 第2引数:講師名の文字列, 第3引数:'catalog-2018.json'に含まれるすべての授業のUTCourseオブジェクトのリスト
    # 出力:
        # 入力の授業名と講師名にマッチするUTCourseオブジェクトを返す 
            # マッチするUTCourseオブジェクトが複数ある場合はいずれか1つを選択して返す
        # マッチするUTCourseオブジェクトがなければNoneを返す
    result = []

    # 入力されたutcオブジェクトリストの全てを確認
    for utc in utcs:
        # タイトルおよび講師名が一致した講義を抽出
        if title.replace(" ", "\u3000") == utc.title_j and lecturer.replace(" ", "\u3000") == utc.name_j:
            result.append(utc)

    return (None if len(result)==0 else result[0])

def course_vectorizer(utc, kwlist):
    # 入力:
        # 第1引数:UTCourseオブジェクト, 第2引数:'course_keyword_list.csv'に含まれるキーワードのリスト
    # 出力:
        # UTCourseオブジェクトの属性, 'title_j', 'Title', 'Schedule', の値を元に授業のベクトルをNumPyの配列として返す
            # 授業ベクトルは、キーワードリストの語彙数と同じ要素数を持つ
            # 属性, 'title_j', 'Title', 'Schedule', のいずれかの値にキーワードが含まれていれば、授業ベクトルの要素のうち、
            # そのキーワードに対応する要素の値を1とし、含まれていなければ値は0とする

    result = np.zeros(len(kwlist), dtype=int)

    for i, word in enumerate(kwlist):
        if (word in utc.title_j) or (hasattr(utc, "Title") and word in utc.Title) or (hasattr(utc, "Schedule") and word in utc.Schedule):
            result[i] = 1

    return result

def cos_vec(v1, v2):
    numer = np.dot(v1, v2)
    denom = np.linalg.norm(v1) * np.linalg.norm(v2)
    return numer / denom

def search_course(title, lecturer):
    # 入力にマッチする授業のUTCourseオブジェクトを探す
    utcs = utcourses()    
    input_course = find_course(title, lecturer, utcs)  

    kwlist = keywords()
    # すべてのUTCourseオブジェクトから各授業のベクトルを作成
    # 以下は入力の授業ベクトルの作成例
    input_vec = course_vectorizer(input_course, kwlist)

    # 入力の授業ベクトルと各授業のベクトルとの類似度を計算
    lecs_and_vecs = []
    for utc in utcs:
        lecs_and_vecs.append([utc, ( cos_vec(input_vec, course_vectorizer(utc, kwlist)) )])

    # 入力授業と類似した授業の授業名, 講師名, 開講学部名, 類似度を各列として検索結果をpandasのデータフレームオブジェクトとして作成
    d = pd.DataFrame({
        "title":      [i[0].title_j      for i in lecs_and_vecs], 
        "lecturer":   [i[0].name_j       for i in lecs_and_vecs], 
        "department": [i[0].department_j for i in lecs_and_vecs],
        "similarity": [i[1] for i in lecs_and_vecs]
    })

    # 検索結果を類似度の降順にしてデータフレームオブジェクトとして返す
    return d.sort_values("similarity", ascending=False)

if __name__ == "__main__":
    result = search_course("コンピュータアーキテクチャ", "坂井　修一").head(20)
    print(result)