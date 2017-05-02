load("Lines.rb")

def connectline
	#接続用変数
	con = 0;
	
	#井の頭戦と小田急線の駅データを受け取る
	ino = inokashira(); oda = odakyuusen();
	
	#乗り継ぎ可能な駅を探す
	for i in 1..ino.length()-1 do	#計測が必要なのは二駅目以降から
		if oda.index(ino[i]) != nil then
			#接続駅を記録
			con = i;
			
			#ループ終了
			break;
		end
	end
	
	#最終的な道順を計算
	connected = ino[0..con] + oda[oda.index(ino[con])+1..oda.length()-1];
	
	#画面に表示
	print "["
	print connected * ",";
	print "]\n";
end



load("galaxyExpresses.rb")


########## 遅いので駄目 ##########
=begin
def connectgalaxy
	#接続用変数
	con = 0;
	
	#line1とline2のデータを得る
	l1 = line1(); l2 = line2();
	
	#乗り継ぎ可能な駅を探す
	for i in 1..l1.length()-1 do	#計測が必要なのは二駅目以降から
		#puts i		### DEBUG ###
		if l2.index(l1[i]) != nil then
			#接続駅を記録
			con = i;
			
			#ループ終了
			break;
		end
	end	
	
	#最終的な道順を計算
	connected = l1[0..con] + l2[l2.index(l1[con])+1..l2.length()-1];
	
	#画面に表示
	print "["
	print connected * ",";
	print "]\n";
end
=end
########## 遅いので駄目 ##########



#connectsearch用ループカウンタグローバル変数
$r = 0;

#.index()を駅順の特徴に即して自作
def connectsearch(a,i,b)
	###aとbが配列 iとjが整数###
	
	#rをグローバル変数にして調べる
	while a[i] >= b[$r] do
		if a[i] == b[$r] then
			#iが正しいindex
			return i;
		end
	
		#rを増やす
		$r+=1;
	end
	
	#見つからなかった場合はnil
	return nil
end


def connectgalaxy
	#接続用変数
	con = 0;
	
	#line1とline2のデータを得る
	l1 = line1(); l2 = line2();
	
	#l1とl2をソート
	l1 = l1.sort(); l2 = l2.sort();
	
	#乗り継ぎ可能な駅を探す
	for i in 1..l1.length()-1 do	#計測が必要なのは二駅目以降から
		if connectsearch(l1,i,l2) != nil then
			#接続駅を記録
			con = i;
			
			#ループ終了
			break;
		end
	end	
	
	#最終的な道順を計算
	connected = l1[0..con] + l2[l2.index(l1[con])+1..l2.length()-1];
	
	#画面に表示
	print "["
	print connected * ",";
	print "]\n";
end