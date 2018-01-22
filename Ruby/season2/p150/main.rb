#coding: UTF-8
=begin
　2017.12.22
　grub
=end


s = "１１７１１７"
puts s
s.gsub!(/０/,"0")
s.gsub!(/１/,"1")
s.gsub!(/２/,"2")
s.gsub!(/３/,"3")
s.gsub!(/７/,"7")
puts s
