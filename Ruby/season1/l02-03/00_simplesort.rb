
#配列aのi番目以降の要素で最小の値の要素番号を見つける
def min_index(a,start)
	#aの末端要素番号を取得
	alast = a.length()-1;
	
	#最小値要素番号格納用変数にstartの値を代入
	min = start;
	
	#探査ループ
	for i in start..alast
		#a[i]がa[min]より小さければ要素番号を代入
		if a[i] < a[min] then
			min = i;
		end
	end
	
	#return
	min;
end


#シンプルソート
def simplesort(a)
  #全要素探索
  for i in 0..(a.length()-1)
    #aのi番目以降の最小値の存在する要素番号を取得
    k = min_index(a,i)
    
    #a[i]とa[k]を交換
    v = a[i]
    a[i] = a[k]
    a[k] = v
  end
  
  #return
  a
end