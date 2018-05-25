# coding: UTF-8
"""
　2018.5.23
　クラスの作成
"""

class Point3D:
    # コンストラクタ
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    # 原点からの距離計算
    def  distance_from_origin(self):
        (self.x**2 + self.y**2 + self.z**2) ** 0.5

    # 他のオブジェクトを用いた座標の設定
    def set(self, obj):
        self.x = obj.x
        self.y = obj.y
        self.z = obj.z

p1 = Point3D(0,0,0)
print(p1)
print(p1.x, p1.y, p1.z)
p2 = Point3D(3,4,5)
print(p2)
p1.set(p2)
print(p1.x, p1.y, p1.z)