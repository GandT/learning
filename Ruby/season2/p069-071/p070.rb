# -*- coding: utf-8 -*-
=begin
　2017.5.4
　ヒアドキュメント
=end

include Math

23.times do |i|
  23.times do |j|
    #計算結果の表示
    print(<<-"EOB")
-----
x: #{i/7.0}
y: #{j/7.0}
sin(x): #{sin(i/7.0)}
cos(y): #{cos(j/7.0)}
sin(x)*sin(x) + cos(y)*cos(y) = #{sin(i/7.0)**2 + cos(j/7.0)**2}
-----
EOB
    sleep(0.2)
  end
end
