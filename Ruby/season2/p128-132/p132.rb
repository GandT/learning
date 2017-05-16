# -*- coding: utf-8 -*-
=begin
　2017.5.16
　演算子オーバーロード
=end

class Vector2D
  # アクセサの設定
  attr_accessor :x, :y
  
  # 初期化処理
  def initialize(x = 0, y = y)
    @x, @y = x, y
  end

  # 加算
  def +(other)
    Vector2D.new(@x + other.x, @y + other.y)
  end

  # 減算
  def -(other)
    Vector2D.new(@x - other.x, @y - other.y)
  end

  # 乗算（内積）
  def *(other)
    @x*other.x + @y*other.y
  end

  # 乗算（外積）
  def **(other)
    @x*other.y - @y*other.x
  end

  # 単項演算子
  def +@
    self.dup
  end
  def -@
    Vector2D.new(-@x, -@y)
  end

  # 配列参照演算子
  def [](index)
    case index
    when 0
      @x
    when 1
      @y
    else
      raise ArgumentError, "#{index}は範囲外です"
    end
  end
  def []=(index, num)
    case index
    when 0
      @x = num
    when 1
      @y = num
    else
      raise ArgumentError, "#{index}は範囲外です"
    end
  end
end

p v1 = Vector2D.new(1,2)
puts "(x,y)=(#{v1.x}, #{v1.y})"
p v2 = Vector2D.new(3,4)
puts "(x,y)=(#{v2.x}, #{v2.y})"
puts "v1 + v2 = (#{(v1+v2).x}, #{(v1+v2).y})"
puts "v1 - v2 = (#{(v1-v2).x}, #{(v1-v2).y})"
puts "v1 * v2 = #{(v1*v2)}"
puts "v1 ** v2 = #{(v1**v2)}"
puts "-v1 = (#{-v1.x}, #{-v1.y})"
puts "v1[0] = #{v1[0]}"
puts "v1[1] = #{v1[1]}"
