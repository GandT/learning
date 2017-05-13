# -*- coding: utf-8 -*-
=begin
　2017.5.12
　ディレクトリの読み出し
=end

dp = Dir.open("./")
while n = dp.read do
  p n
end
dp.close

puts "------------------"

dp = Dir.open("./")
dp.each{ |n|
  p n
}
dp.close
