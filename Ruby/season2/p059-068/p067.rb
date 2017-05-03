# -*- coding: utf-8 -*-
=begin
　2017.5.3
　配列の自動作成
=end

require "pp"

a = Array.new(10) do |i|
  array = []
  10.times do |j|
    array.push(i+j)
  end
  array
end

pp a
