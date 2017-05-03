# -*- coding: utf-8 -*-
=begin
　2017.5.3
　切り上げ・切り下げ・四捨五入・型変換
=end

module NumPrint
  def to_i_p num
    print "【to_i】\t"
    print num, " -> ", num.to_i, "\n"
  end
  module_function :to_i_p
  def round_p num
    print "【round】\t"
    print num, " -> ", num.round, "\n"
  end
  module_function :round_p
  def ceil_p num
    print "【ceil】\t"
    print num, " -> ", num.ceil, "\n"
  end
  module_function :ceil_p
  def floor_p num
    print "【floor】\t"
    print num, " -> ", num.floor, "\n"
  end
  module_function :floor_p
  def to_r_p num
    print "【有理数】\t"
    print num, " -> ", num.to_r, "\n"
  end
  module_function :to_r_p
  def to_c_p num
    print "【複素数】\t"
    print num, " -> ", num.to_c, "\n"
  end
  module_function :to_c_p
  def all num
    to_i_p num
    ceil_p num
    floor_p num
    round_p num
    to_r_p num
    to_c_p num
  end
  module_function :all
end



def main
  puts "-----"
  sleep(1)
  NumPrint.all 0.5
  puts "-----"
  sleep(1)
  NumPrint.all -2.8
  puts "-----"
  sleep(1)
  NumPrint.all -999999999999999999999999.99
  puts "-----"
  sleep(1)
  NumPrint.all 100.0
  puts "-----"
end


main
