class Sma
  CHARS = 128
  #コンストラクタ
  def initialize(pat)
    #検索文字列の記録
    @pat = pat

    #δ関数の二次元配列の初期化
    @delta = Array.new(@pat.length+1)
    for i in 0..@delta.length-1
      @delta[i] = Array.new(CHARS,0)    # 状態 x 文字
    end
    
    #オートマトンの作成
    for q in 0..@pat.length      # q文字目までマッチした状態で、
      for i in 0..CHARS-1      # 次の文字がiだった時、
        k = [@pat.length,q+1].min
        while !suffix(sub(@pat,0,k-1),@pat[0..q-1]+i.chr)
          k -= 1 # 次の文字を含めた時、k文字目まで検索文字列と一致
        end
        @delta[q][i] = k                   # 次の状態はk。iは文字コード(ASCII)
      end
    end
  end

  #部分配列抽出関数
  def sub(s,i,j)
    if i<=j
      s[i..j]
    else
      ""
    end
  end

  #接尾辞かどうかの判定関数
  def suffix(s, body)
      return (s.length <= body.length && s == sub(body,-s.length,-1));    #sがbodyの接尾辞かどうかを判定する
  end
  
  #状態繊維表に基づく
  def match(t)
    #初期値として状態0を設定
    q = 0
    
    #入力文字列の長さだけループ
    for i in 0..t.length-1
      #遷移を繰り返す(t[i]は文字列tのi番目の文字の文字コード。i番目の文字そのものはt[i..i])
      q = @delta[q][t[i].ord]
      
      #最終状態に到達した場合到達位置を表示
      if q == @pat.length
        print("match at ",(i+1-@pat.length),"\n");
      end
    end
  end
end

