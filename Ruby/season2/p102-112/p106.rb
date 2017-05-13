# -*- coding: utf-8 -*-
=begin
　2017.5.12
　ワイルドカードを用いたフォルダ・ファイル名の取得
=end

puts Dir.pwd
puts "において、"
Dir.glob("*"){ |f|
  print f, "\t"
}
puts "\nであり、"
Dir.glob(".*"){ |hf|
  print hf, "\t"
}
puts "\nである"
