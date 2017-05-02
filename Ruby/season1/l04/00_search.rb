#線形探索
def lsearch(array,word)
	#配列の長さを取得
	len = array.length();
	
	#配列を探索
	for i in 0..len-1
		#検索語が見つかれば配列番号を返して終了
		if array[i] == word then
			#return
			return i;
		end
	end
	
	#見つからなければnilを返して終了
	return nil;
end



#二分探索
def bsearch(array,word)
	#下限と上限の初期値を設定
	unnum = 0;
	ovnum = array.length()-1;
	
	#上限より下限大きくない限りループ
	while unnum <= ovnum do
		#中間値を求める
		mdnum = (unnum + ovnum) / 2;
		
		#求めるものが見つかった場合
		if array[mdnum] == word then
			#番号を返して終了
			return mdnum;
		end
		
		#求めるものが中間より小さい場合
		if array[mdnum] > word then
			#上限を引き下げる
			ovnum = mdnum - 1;
		end
		
		#求めるものが中間より大きい場合
		if array[mdnum] < word then
			#下限を引き上げる
			unnum = mdnum + 1;
		end
	end
	
	#見つからなければnilを返して終了
	return nil;
end