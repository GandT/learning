load("00_mergesort.rb")


#探索数値と誤差の設定
x = 100;
esp = 50;

#####探索対象配列準備#####
ar = Array.new(2000);
for i in 0..1999 do
    ar[i] = rand() * 20000;
end
ar = mergesort(ar);
print "配列："
print ar
print "\n\n\n"
#######################


#線形探索
def lsearch(array,num)
	#配列の長さを取得
	len = array.length();
	
	#配列を探索
	for i in 0..len-1
		#検索語が見つかれば配列番号を返して終了
		if array[i] == num then
			#return
			return i;
		end
        
        #配列格納数値が受け取った数字よりも大きくなっていたら終了
        if array[i] > num then
            return i;
        end
	end
    
    #最後まで見つからなければ配列の長さを返して終了
    return len;
end



#二分探索
def bsearch(array,num)
	#下限と上限の初期値を設定
	unnum = 0;
	ovnum = array.length()-1;
	
	#上限より下限大きくない限りループ
	while unnum <= ovnum do
		#中間値を求める
		mdnum = (unnum + ovnum) / 2;
		
		#求めるものが見つかった場合
		if array[mdnum] == num then
			#番号を返して終了
			return mdnum;
		end
		
		#求めるものが中間より小さい場合
		if array[mdnum] > num then
			#上限を引き下げる
			ovnum = mdnum - 1;
		end
		
		#求めるものが中間より大きい場合
		if array[mdnum] < num then
			#下限を引き上げる
			unnum = mdnum + 1;
		end
	end
	
	#見つからなければ上と下の大きい方を返して終了
	return (unnum + ovnum + 1) / 2;
end



#近似値探索
def nearnum(array,num)
    #受け取った配列の長さを記録
    len = array.length();
    
    
    #####線形探索#####
    print "線形探索："
    
    #近似位置を受け取る
    nnum = lsearch(array,num);
    
    #配列不正アクセス防止のため長さを確認
    if nnum > len then
        nnum -= 1;
    end
    
    #比較してnumに近い方の添字を表示
    if (array[nnum]-num).abs > (array[nnum-1]-num).abs then
        print nnum-1;
    else
        print nnum;
    end
    
    puts "";
    ################
    
    
    #####二分探索#####
    print "二分探索："
    nnum = bsearch(array,num);
    if (array[nnum]-num).abs > (array[nnum-1]-num).abs then
        print nnum-1;
    else
        print nnum;
    end
    
    puts "";
    ################
end


#誤差範囲探索
def rangenum(array,num,range)
    #受け取った配列の長さを記録
    len = array.length();
    
    #####線形探索#####
    print "線形探索："
    
    #近似位置を受け取る
    nnum = lsearch(array,num);
    
    #配列不正アクセス防止のため長さを確認
    if nnum > len then
        nnum -= 1;
    end
    
    #上方向の確認
    lans = [];
    i = 0;
    while array[nnum+i] < num + range do
        #答えに追加
        lans << nnum + i;
        
        #次を調べる
        i += 1;
        
        #配列参照場所がlenを超えてしまったら終了
        if nnum + i >= len then
            break;
        end
    end
    
    #下方向の確認
    i = 1;
    while array[nnum-i] > num - range do
        lans << nnum - i;
        i += 1;
        if nnum - i < 0 then
            break;
        end
    end
    
    #答えの表示
    lans = mergesort(lans);
    print lans;
    
    puts "";
    ################
    
    
    
    #####二分探索#####
    print "二分探索："
    nnum = bsearch(array,num);
    if nnum > len then
        nnum -= 1;
    end
    bans = [];
    i = 0;
    while array[nnum+i] < num + range do
        bans << nnum + i;
        i += 1;
        if nnum + i >= len then
            break;
        end
    end
    i = 1;
    while array[nnum-i] > num - range do
        bans << nnum - i;
        i += 1;
        if nnum - i < 0 then
            break;
        end
    end
    bans = mergesort(lans);
    print bans;
    
    puts "";
    ################

    
end

nearnum(ar,x);
print "\n\n\n"
rangenum(ar,x,esp);
