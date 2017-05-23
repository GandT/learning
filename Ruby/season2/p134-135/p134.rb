# -*- coding: utf-8 -*-
=begin
　2017.5.23
　ブロックの引き渡し
=end


pr = Proc.new do
  print "こん"
end

print "ばのさげ"

=begin
こうやって渡す方法はない
5.times pr.call
=end

pr.call

puts "たん"
