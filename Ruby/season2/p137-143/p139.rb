# -*- coding: utf-8 -*-
=begin
　2017.5.25
　Enumerableモジュールの導入
=end

require "date"
require "pp"


# ゲーム情報
class Game
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


# ゲームリスト
class GameList
  # 変数宣言
  @gamelist

  # コンストラクタ
  def initialize
    @gamelist = Array.new
  end

  # 追加
  def add(book)
    @gamelist.push(book)
  end

  # データ数
  def length
    return @gamelist.length
  end

  # データの書き換え
  def []=(n, game)
    @gamelist[n] = game
  end

  # データ取得
  def [](n)
    return @gamelist[n]
  end

  # データ削除
  def delete(game)
    @gamelist.delete(game)
  end

  # 逐次データ取り出し
  def each
    @gamelist.each do |game|
      yield game
    end
  end

  # 逐次タイトル取り出し
  def each_title
    @gamelist.each do |title|
      yield game.title
    end
  end

  # 逐次著者名・タイトルセット取り出し
  def each_set
    @gamelist.each do |book|
      yield game.title, game.creator
    end
  end

  # タイトルマッチング
  def find_by_title(title)
    if block_given?
      @gamelist.each do |game|
        if title =~ game.title
          yield game
        end
      end
    else
      result = []
      @booklist.each do|game|
        if author =~ game.title
          result << game
        end
      end
      return result
    end
  end

  # 著者マッチング
  def find_by_creator(creator)
    if block_given?
      @gamelist.each do |game|
        if creator =~ game.creator
          yield game
        end
      end
    else
      @gamelist.select do |game|
        creator =~ game.creator
      end
    end
  end
end

# EnumerableのMix-in
class GameList
  include Enumerable
end


# 作者名の設定
name = {
  Ｇ＆Ｔ: "Ｇ＆Ｔ",
  トルネードＧ＆Ｔ: "Ｇ＆Ｔ",
  ⑧: "れーや",
  れーや: "れーや",
  よっすぃ〜: "ほろろん",
  ほろろん: "ほろろん",
  John: "John",
  Katsuby: "John"
}

# ゲームの設定
gl = GameList.new
gl.add(Game.new("狂気と混乱の機械魔獣", name[:Ｇ＆Ｔ], Date.new(2007), "RPG"))
gl.add(Game.new("Last World", name[:⑧], Date.new(2007), "RPG"))
gl.add(Game.new("WORLD OF THE NEXT", name[:John], Date.new(2007)))
gl.add(Game.new("ChaosWorld　ー冷タイ世界ニ生キル者ー", name[:Ｇ＆Ｔ], Date.new(2009), "STG"))
gl.add(Game.new("THE・二階をつくろう", name[:よっすぃ〜], Date.new(2007), "SLG"))
gl.add(Game.new("論理飛躍トレーニング", name[:トルネードＧ＆Ｔ], Date.new(2017), "Quiz"))
gl.add(Game.new("THE COM", name[:ほろろん], Date.new(2016), "STG"))

# タイトルの取り出し
puts "【タイトル一覧】"
titles = gl.collect{ |game|
  game.title
}
pp titles

# ソート
puts "【ソート後】"
pp gl.sort.collect{ |game|
  game.title
}

puts "【すべてジャンルが登録済み】"
p gl.all?{ |g|
  g.genre
}
puts "【ひとつはジャンルが登録済み】"
p gl.any?{ |g|
  g.genre
}
