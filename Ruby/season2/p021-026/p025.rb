# -*- coding: utf-8 -*-
=begin
　2017.5.2
　==と===
=end

puts "==","==="
puts "【(1..3) ? 2】"
p ((1..3)  == 2)
p ((1..3) === 2)
puts "【/exp/ ? \"expression\"】"
p (/exp/  == "expression")
p (/exp/ === "expression")
puts "【String ? \"学園\"】"
p (String  == "学園")
p (String === "学園")
puts "【\"学園\" ? String】"
p ("学園"  == String)
p ("学園" === String)
puts "【Array ? [1,1,7,1,1,7,\"学園\"]】"
p (Array  == [1,1,7,1,1,7,"学園"])
p (Array === [1,1,7,1,1,7,"学園"])
