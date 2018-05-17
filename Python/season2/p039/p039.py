# coding: UTF-8
"""
　2018.5.11
　CSVとjsonを用いた情報の整理
"""

import csv
import json

# ハッシュの値によるソートのジェネレーター
def sort_hashvalue(hash):
    for k,v in sorted(hash.items(), key=lambda x:x[1], reverse=True):
        yield (k, v)

def count_keyword(name):
    # 生ファイルを開く
    fp1 = open("course_keyword_list.csv", "r", encoding="utf-8")
    fp2 = open("catalog-2018.json", "r", encoding="utf-8")
    fp3 = open("output.csv", "w", encoding="utf-8")

    # CSVとjsonを扱う形に変換
    cin = csv.reader(fp1)
    jin = json.load(fp2)
    cout = csv.writer(fp3)

    # キーワードリストの作成
    keywords = []
    for row in cin:
        keywords.append(row[0])
    print(keywords)

    # 授業題目リストの作成
    lectures = {}
    for lecture in jin:
        # 学部が合わない場合は無視
        if name != lecture["department_j"]:
            continue  
        # ワードリストから一致があるものを検索しカウント
        for word in keywords:
            if word in lecture["title_j"]:
                # 既に登録されているものかどうかで分岐
                if word in lectures.keys():
                    lectures[word] += 1
                else:
                    lectures[word] = 1
    # lecturesを辞書から数値順に並んだ配列へ変換
    lectures = [pair for pair in sort_hashvalue(lectures)]
    print(lectures)

    # CSV出力
    cout.writerows(lectures)

    # 生ファイルを閉じる
    fp1.close()
    fp2.close()
    fp3.close()


count_keyword("経済学部")