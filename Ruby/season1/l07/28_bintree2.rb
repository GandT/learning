# -*- coding: utf-8 -*-
#
# 二分木
#

class Bintree2
  def initialize(key,data)
    #受け取ったキーとデータの値を保存
    @key = key
    @data = data
    
    #左右の葉の情報を初期化
    @left = nil
    @right = nil
  end
  
  # キー=eの頂点を検索
  def search(e)
    # 頂点のキーより小さいものは左の子孫にある(あるとすれば)
    if e < @key
      # 左の子がなければない
      if @left == nil
        return nil
      # 左の子があれば左の子(の下を)再帰的に検索
      else
        return @left.search(e)
      end
      
    # 頂点のキーより大きいものは右の子孫にある(あるとすれば)
    elsif e > @key
      if @right == nil
        return nil
      else
        return @right.search(e)
      end
    else # e == @keyの場合
      return self
    end
  end

  # キー(e)のデータ(d)を挿入
  def insert(e,d)
    # 頂点のキーより小さいものは左の子孫にある
    if e < @key
      if @left == nil
        # 左の子がなければ、そこに頂点を作って登録
        @left = Bintree2.new(e,d)
      else
        # そうでなければ左の子(の下に)再帰的に挿入
        @left.insert(e,d)
      end
    
    # 頂点のキーより大きいものは右の子孫にある
    elsif e > @key
      if @right == nil
        @right = Bintree2.new(e,d)
      else
        @right.insert(e,d)
      end
    end
    
    # 既にある頂点のキーと一致した場合は変更しないことにする
  end

  def data # データのアクセッサー
    return @data
  end
end

def test
  root = Bintree2.new(0,"") # 以下で、root.insertができるように、ダミーの根を作っておく。
  while true
    # キーを入力を受け取る（改行文字は削除）
    print "key="
    line = gets.chomp
    
    #数字が受け取られたかどうかの判断
    if line != ""
      # 文字を数値に変換
      a = line.to_i
      
      # 正の値は挿入として扱う
      if a>0
        # データを入力
        print "data="
        line = gets.chomp
        
        # 入力データを挿入する
        if line != ""
          root.insert(a,line)
          
        # 入力データがなければエラー表示
        else
          print "data must be a word\n"
        end
        
      # 負の値は検索として扱う
      elsif a<0
        # ループ用変数にaの符号反転を代入
        rp = -a;
        
        #ループ
        for i in 0..rp-1
        
          # データを検索し結果を保存
          n = root.search(rp-i)
        
          # 見つかったデータを表示
          if n != nil
            print "data=",n.data,"\n"
            
            # 終了
            break;
          end
          
          # 見つからなかったらエラーを表示
          if i == rp-1
            print "data for key=",-a," not found\n"
          end
        end
      
      # 0だったら終了
      else
        break
      end
      
    # 次が整数でない場合
    else
      #警告文を表示
      print "key must be a number"
    end
  end
end
