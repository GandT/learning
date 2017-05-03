# -*- coding: utf-8 -*-
=begin
　2017.5.3
　クラスメソッドの様々な記法
=end

class CMtest
  def CMtest.a
    p "a" 
  end
  def self::b
    p "b"
  end
  class << CMtest
    def c
      p "c"
    end
    def d
      p "d"
    end
  end
  class << self
    def e
      p "e"
    end
    def f
      p "f"
    end
  end
end


CMtest.a
CMtest.b
CMtest.c
CMtest.d
CMtest.e
CMtest.f

CMtest::a
CMtest::b
CMtest::c
CMtest::d
CMtest::e
CMtest::f
