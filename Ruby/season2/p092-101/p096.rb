# -*- coding: utf-8 -*-
=begin
　2017.5.11
　stringioライブラリ
=end


require "stringio"

sstd = StringIO.new

sstd.print("こんにゃく")
sstd.puts("畑で")
# sstd.p("フルーツ")　→privateメソッドなのでダメとのこと
sstd.putc(0x46)
sstd.putc(0x72)
sstd.putc(0x75)
sstd.putc(0x69)
sstd.putc(0x74)
sstd.putc(0x73)
sstd.printf("唐辛子のような巨大な%08dによって都庁から半径100kmの地域は壊滅的な被害を受けた。政府はこの自体を受け緊急に%s%f%s", 2395878932471, "momomomomomomomomomomomomomomomomomomomomomomomomomomomomomo",329847.3253452,"タモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリタモリ\n")
sstd.rewind

print sstd.read
