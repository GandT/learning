load("./is_even.rb")
load("./make2d.rb")


#整列された二つの配列を整列された状態でマージ
def merge(a,b)
  #二つの配列の長さを合わせ長さの配列を作る
  c = make1d(a.length()+b.length())

  #変数の初期化
  ia=0				#配列aの現在の要素番号
  ib=0				#配列bの現在の要素番号
  ic=0				#併合後配列cの現在の要素番号

  #小さい方から順に併合後配列へ値を移動
  while ia < a.length() && ib < b.length()
    #aからbへ
    if a[ia] < b[ib]
      c[ic] = a[ia]
      ia = ia + 1
      ic = ic + 1
    
    #bからcへ
    else
      c[ic] = b[ib]
      ib = ib + 1
      ic = ic + 1
    end
  end
  
  #残った要素を全てcに移動
  if ia != a.length() then			#aが残った場合
    for i in ia..a.length()-1
      c[ic] = a[ia]
      ia = ia + 1
      ic = ic + 1
    end
  end
  if ib != b.length() then			#bが残った場合
    for i in ib..b.length()-1
      c[ic] = b[ib]
      ib = ib + 1
      ic = ic + 1
    end
  end
  
  #return
  c
end


#マージソート
def mergesort(a)
  #配列の長さを取得
  n = a.length()
  
  #n×1の二次元配列を取得
  from = make2d(n,1)
  
  #初期値の設定
  for i in 0..(n-1)
    from[i][0] = a[i] 
  end
  
  #配列の長さが1になるまで折りたたみを続ける
  while n > 1
    #toにfromの半分の長さの配列を用意
    to = make1d((n+1)/2)
    
    #奇偶併合する形でfromからtoへ値を移動
    for i in 0..(n/2-1)
      to[i] = merge(from[i*2], from[i*2+1])
    end
    
    #奇数の場合最後の要素を移動
    if !is_even(n)
      to[(n+1)/2-1]=from[n-1]
    end
    
    #fromにtoを代入
    from=to
    
    #from配列の長さ値を再設定
    n=(n+1)/2
  end
  
  #return
  from[0]
end