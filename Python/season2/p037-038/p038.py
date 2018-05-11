# coding: UTF-8
"""
　2018.5.2
　巨大jsonの検索
"""

import json

def search_catalog(s):
    answers = []
    with open("catalog-2018.json", "r", encoding="utf-8") as f:
        j = json.load(f)
        for lecture in j:
            hit = False
            
            # 探索
            if s in lecture["title"]:
                hit = True
            if s in lecture["title_j"]:
                hit = True
            if "Title" in lecture.keys():
                if s in lecture["Title"]:
                    hit = True
            if "Schedule" in lecture.keys():
                if s in lecture["Schedule"]:
                    hit = True
            
            # ヒットしていた場合は結果に追加
            if hit:
                answers.append(lecture)
    
    return answers

print(search_catalog('Python'))

jsi = [i for i in search_catalog('Python')]
with open("python_courses.json", "w") as f:
    json.dump(jsi, f)
