# -*- coding: utf-8 -*-

=begin
　2017.4.27
　include動作確認
=end

pi = 3.141592

puts Math.sin(pi * 0.4)
puts Math.cos(pi * 0.4)

include Math

puts sin(pi*0.3)
puts cos(pi*0.3)

theta = pi * rand(100) / 100
print "rand:",theta,"\n"

print "(sinθ)^2 + (cosθ)^2 = 1 : "
print sin(theta)*sin(theta) + cos(theta)*cos(theta)
puts""
