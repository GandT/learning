# -*- coding: utf-8 -*-
=begin
　2017.5.25
　Comparebleモジュールの導入
=end

require "date"
require "pp"


# 書籍情報
class Game
  # Mix-in
  include Comparable

  # アクセサの設定
  attr_accessor :title, :creator, :year, :genre

  # コンストラクタ
  def initialize(title, creator, year = Date.now, genre = nil)
    # データ代入
    @title = title
    @creator = creator
    @year = year
    @genre = genre
  end

  # 順序比較
  def <=>(other)
    ret = @genre.to_s <=> other.genre.to_s

    # 別ジャンルの場合
    return ret

    # 同一ジャンルの場合タイトル比較
    return @title <=> other.title
  end
end



array = []
array << Game.new("狂気と混乱の機械魔獣", "Ｇ＆Ｔ", Date.new(2007), "RPG")
array << Game.new("Last World", "⑧", Date.new(2007), "RPG")
array << Game.new("WORLD OF THE NEXT", "John", Date.new(2007))
array << Game.new("ChaosWorld　ー冷タイ世界ニ生キル者ー", "Ｇ＆Ｔ", Date.new(2009), "STG")
array << Game.new("Chaos World　〜future of hopes〜", "Ｇ＆Ｔ", Date.new(2011), "STG")
array << Game.new("WONDERFUL WORLD", "れーや", Date.new(2011), "STG")

# ソート結果
pp array.sort!

# 正しくソートできているかの確認
(array.length-1).times{ |i|
  p array[i] <= array[i+1]
}
