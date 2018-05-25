# coding: UTF-8
"""
　2018.5.23
　クラスの継承
"""

class SimpleCourse:
    def __init__(self, title_j, name_j, slot):
        self.title_j = title_j
        self.name_j = name_j
        self.slot = slot

class SimpleCourseE(SimpleCourse):
    def __init__(self, title_j, title_e, name_j, name_e, slot):
        # 親クラス分の初期化
        super().__init__(title_j, name_j, slot)
        # 独自メンバ変数の初期化
        self.title_e = title_e
        self.name_e = name_e
    
    def info_j(self):
        return (self.title_j, self.name_j)

    def info_e(self):
        return (self.title_e, self.name_e)

sce = SimpleCourseE("英語", "English", "加藤", "Kato","1-6")
print(sce.info_j())
print(sce.info_e())