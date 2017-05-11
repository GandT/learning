# -*- coding: utf-8 -*-
=begin
　2017.5.11
　標準出力確認
=end

if $stdin.tty?
  puts "シェルだよ"
else
  puts "シェルではなし"
end
