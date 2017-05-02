load("00_sma.rb")
load("longA.rb")

#探したい文字列の設定
strab = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
strla = longA;
sma = Sma.new(strab);

#メッセージ表示
puts "SMAによる探索を開始"

#探索し結果を表示
for i in 1..100
	sma.match(strla)
end
puts "SMAによる探索を終了"

#メッセージ表示
print "\n\n"
puts "線形探索による探索を開始"

#探索し結果を表示
for r in 1..100
	last = strab.length()-1;
	roop = strla.length()-1;
	for i in 0..roop
		if strab == strla[i..i+last] then
			print("match at ",i,"\n");
		end
	end
end
puts "線形探索による探索を終了"


#以下コメント
=begin
【実行速度の差について】
　一回のみの探索ではSMAでも線形探索でもすぐに終わってしまうため差がわからなかったためそれぞれ100回ずつループさせた。
　しかし、100回であっても両者の実行速度の間に体感的な差はなかった。
=end