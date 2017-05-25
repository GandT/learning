# -*- coding: utf-8 -*-
=begin
　2017.5.25
　Mix-inのincludeメソッド
=end


module Mo
  def func
    puts "ぽよぽよなんきんだるまちゃん"
  end
end


class Cl
  include(Mo)
end


Cl.new.func
