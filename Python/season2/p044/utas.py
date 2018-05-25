# coding: UTF-8

class UTCourse:
    def __init__(self, hash):
        # ハッシュの読み出しで属性作成
        for key, value in hash.items():
            if key == "year":
                setattr(self, key, int(value))
            else:
                setattr(self, key, value)