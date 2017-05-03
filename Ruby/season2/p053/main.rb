# -*- coding: utf-8 -*-
=begin
　2017.5.3
　剰余演算
=end


class DivAll
  # コンストラクタですべて呼び出す
  def initialize a, b
    div_print a, b
    per_print a, b
    divmod_print a, b
    modulo_print a, b
    remainder_print a, b
  end

  # 各種計算の表示
  def div_print a, b
    print a, " / ", b, " = ", a/b, "\n"
  end

  def per_print a, b
    print a, " % ", b, " = ", a%b, "\n"
  end

  def divmod_print a, b
    divarray = a.divmod(b)
    print a, " ÷ ", b, " = ", divarray[0], " あまり ", divarray[1], "\n"
  end

  def modulo_print a, b
    print a, " mod ", b, " = ", a.modulo(b), "\n"
  end

  def remainder_print a, b
    print a, " ÷ ", b, " ≡ ", a.remainder(b), "\n"
  end
end


def main
  DivAll.new(10, 3)
  puts "-----" 
  sleep(1)
  DivAll.new(10.0, 3.0)
  puts "-----" 
  sleep(1)
  DivAll.new(-10, 4.5)
  puts "-----" 
  sleep(1)
  DivAll.new(-100.0, -11.1)
end


main
