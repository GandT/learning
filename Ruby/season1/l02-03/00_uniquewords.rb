load("00_mergesort.rb")
load("00_search.rb")
load("pg10.rb")


#重複削除関数の定義部分を「06_uniquewords.rb」から独立
def uniquewords(a)
	#ソート
	s = mergesort(a);
	puts("sort完了");
	
	
	#unique配列に第一要素だけ移動
	u = s[0..0];
	
	#重複削除ループ
	for i in 1..s.length()-1 do
		#一つ前と同じでなければ配列に追加
		if s[i] != s[i-1] then
			u << s[i];
		end
	end
	
	#return
	return u;
end
