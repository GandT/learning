# -*- coding: utf-8 -*-
=begin
　2017.5.3
　ビット演算
=end


# 下位8ビット表示
def print_bit num
  printf("%08b\n", num & 0b11111111)
end

def main
  print_bit 0b1111_0000
  print_bit 0b1111_0000 & 0b1010_1010
  print_bit 0b1111_0000 | 0b1010_1010
  print_bit 0b1111_0000 ^ 0b1010_1010
  print_bit ~0b1001_1001
  print_bit 0b1111_0000 >> 2
  print_bit 0b1111_0000 << 2
  printf "%032b\n", -1 >> 1
  printf "%032b\n", -1 << 1
end


main
