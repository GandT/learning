# -*- coding: utf-8 -*-
=begin
　2017.5.3
　分数と複素数
=end

def add_print (num1, num2)
  print num1, " + ", num2, " = ", num1+num2, "\n"
end


def mul_print (num1, num2)
  print num1, " * ", num2, " = ", num1*num2, "\n"
end


def main
  add_print Rational(3,4), Rational(7,18)
  add_print  Complex(2,3),  Complex(3, 5)
  mul_print Rational(3,4), Rational(7,18)
  mul_print  Complex(2,3),  Complex(3, 5)
end


main
