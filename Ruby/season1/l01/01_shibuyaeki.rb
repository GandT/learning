load("Lines.rb")

#品川駅から渋谷駅まで回転しながら到達することを目標とするプログラム
#def arrive_at_shibuya()
	#路線図を読み込む
	t = yamanotesen;
	
	#長さを受け取る
	len = t.length;
	
	#現在の駅座標
	station = t.index("品川駅");
	
	#駅ループ
	while(1)
		#4駅移動
		station += 4;
		
		#回転調整
		station %= t.length();
		
		#現在の駅名を表示
		puts(t[station]);
		
		#渋谷駅なら終了
		if t[station] == "渋谷駅" then
			break;
		end
	end
#end
