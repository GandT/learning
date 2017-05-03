# -*- coding: utf-8 -*-
=begin
　2017.5.3
　catchとthrow
=end


def main
  catch(:あのあれ) do
    puts "観自在菩薩"
    puts "行深般若波羅蜜多時"
    puts "照見五蘊皆空"
    puts "度一切苦厄"
    # throw :そうでもない
    # (ないものを投げてはいけないらしい)
    puts "舎利子"
    puts "色不異空空不異色"
    puts "色即是空空即是色"
    puts "受想行識亦復如是"
    throw :あのあれ
    puts "舎利子"
    puts "是諸法空相不生不滅"
    puts "不垢不浄不増不減"
    puts "是故空中無色無受想行識"
  end
end


main
