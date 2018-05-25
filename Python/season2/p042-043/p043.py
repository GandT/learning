# coding: UTF-8
"""
　2018.5.23
　モジュールファイルのimport
"""

import json
import sys

rfp = open(sys.argv[1], "r", encoding="utf-8")
wfp = open("all_" + sys.argv[1], "w", encoding="utf-8")

jin = json.load(rfp)
jout = []
for lect in jin:
    if lect["name_j"] == "全教員":
        jout.append(lect)

json.dump(jout, wfp, indent=4, ensure_ascii=False)

rfp.close()
wfp.close()

