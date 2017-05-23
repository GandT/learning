# -*- coding: utf-8 -*-

require "date"


# 書籍情報
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
