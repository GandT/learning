# -*- coding: utf-8 -*-
=begin
　2017.5.4
　文字列分割
=end

str = File.read("shark.txt")

p str.split(/ /)
p str.split(/./)
p str.unpack("a10a10a10a10a10a100a*")

str = File.read("鮫.txt")

p str.split(/ /)
p str.split(/。/)
p str.unpack("a10a10a10a10a10a100a*")
