# -*- coding: utf-8 -*-
=begin
　2017.5.25
　継承関係の表示
=end

class C1
  def C1.descript
    print "Nothing at all.\n"
  end
end

class C2 < C1
  def nonoon
    1000.times{print "vvWVwvWWwvvwvwWvwvWvvwvwvwvwvVWVVWVWVWvwvvwvwv"}
  end
end

module M1
  def mi
    print "mi"
  end
end

module M2
  def mi
    print "mimi"
  end
end

class C3 < C2
  include M1
  include M2
end


puts "【SuperClass】"
p C3.superclass
puts "【Ancestors】"
p C3.ancestors
