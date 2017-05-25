# -*- coding: utf-8 -*-
=begin
　2017.5.25
　Mix-inによるクラスメソッドとインスタンスメソッド
=end

module Test
  module ClassMethod
    def me1
      puts "くらす〜"
    end
  end
  module InstanceMethod
    def me2
      puts "くらさない〜"
    end
  end
end


class Tst
  # クラスメソッド
  extend Test::ClassMethod
  # インスタンスメソッド
  include Test::InstanceMethod
end


t = Tst.new
Tst.me1
t.me2
