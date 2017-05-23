# -*- coding: utf-8 -*-
=begin
　2017.5.23
　ブロック処理の自作
=end

require "date"
require "pp"
require "./class"


# ゲームリストの初期化
gl = GameList.new

# ゲームの設定
gl.add(Game.new("狂気と混乱の機械魔獣", "Ｇ＆Ｔ", Date.new(2007), "RPG"))
gl.add(Game.new("Last World", "⑧", Date.new(2007), "RPG"))
gl.add(Game.new("WORLD OF THE NEXT", "John", Date.new(2007)))
gl.add(Game.new("ChaosWorld　ー冷タイ世界ニ生キル者ー", "Ｇ＆Ｔ", Date.new(2009), "STG"))

# 情報表示
pp gl[0]
pp gl[1]
pp gl[2]
pp gl[3]

# マッチング
puts "【Ｇ＆Ｔ】"
gl.find_by_creator(/Ｇ＆Ｔ/){ |g|
  p g.title
}
