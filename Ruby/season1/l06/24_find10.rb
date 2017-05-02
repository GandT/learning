# -*- coding: utf-8 -*-
# 式木を表すノードのクラス
# 簡単のため、演算ノードと葉を兼用
#


######四則演算木クラス（累乗を追加）#####
class ParseNodes
  #初期化関数
  def initialize(op,left=nil,right=nil)
    @op = op # 演算子
    @left = left # 左の子(葉の時は使用しない)
    @right = right # 右の子(葉の時は使用しない)
  end
  
  # 式の値を再帰的に計算する
  def value
    
    # @opが数値なら葉
    if @op.class != String
      return @op                  # 葉ならその値を返す
    
    # @opが数値でないなら演算を行う
    else
    
      #数値の代入
      l = @left.value  # 左の子の値
      r = @right.value # 右の子の値
      
      #四則演算を計算
      case @op # @opの値によって場合分け
      when "+"
        return l+r
      when "-"
        return l-r
      when "*"
        return l*r
      when "/"
        return l/r        # ※lとrが整数の場合は整数の割り算。実数の割り算をしたい場合はl.to_f/rなどとする。
      when "^"
        return l**r
      end
    end
  end
  
  #演算子を別の演算子に書き換える
  def opchange(newop)
      #opが演算子ならば処理を行う
      if @op.class == String
        #書き換え
        @op = newop;
      end
  end
  
  #演算子をランダムに書き換える
  def randomchange
    #乱数を生成
    r = rand(4)
    
    #乱数の値に応じて書き換え
    case r
      when 0; opchange("+")
      when 1; opchange("-")
      when 2; opchange("*")
      when 3; opchange("/")
    end
    
    #左右にも適用
    if @op.class == String
      @left.randomchange
      @right.randomchange
    end
  end
  
  # in orderの文字列に変換する
  def inorder
    #数値か計算式か判別
    if @op.class != String
      return @op.to_s # 葉ならその値の文字列
    else
      return "(" + @left.inorder + @op + @right.inorder + ")"
    end
  end
  
  # pre orderの文字列に変換する
  def preorder
    #数値か計算式か判別
    if @op.class != String
      return @op.to_s  # 葉ならその値の文字列
    else
      return @op + "(" + @left.preorder + "," + @right.preorder + ")"
    end
  end
  
  # post orderの文字列に変換する
  def postorder
      #数値か計算式か判別
    if @op.class != String
      return @op.to_s  # 葉ならその値の文字列
    else
      return @left.postorder + " " + @right.postorder + @op
    end
  end
end



#####四則演算木クラスのテスト用関数#####
def test
  #計算式を設定
  x = ParseNodes.new("+",
                   ParseNodes.new("+",
                                  ParseNodes.new(1.0),
                                  ParseNodes.new("+",ParseNodes.new(1.0),ParseNodes.new(9.0))
                                  ),
                   ParseNodes.new(9.0)
                   )
                   
  # in orderで計算結果を表示
  puts "変換前："
  print x.inorder,"=",x.value,"\n"
  
  #1000回試行
  for i in 1..1000
    x.randomchange
    
    #10が出たら終了
    if x.value == 10
      break
    end
  end
  
  #10が見つかっていなければ10になる値は作れないと見なし終了
  if x.value != 10
    puts "10になる値は作れない"
  end
  
  # in orderで計算結果を表示
  puts "変換後："
  print x.inorder,"=",x.value,"\n"
end



#テスト用関数の実行
test



#以下コメント
=begin
　演算子を順番に変換していく方法が思いつかなかったためランダムに変更して正解が出たら終了するという方式を採用した。
　Rubyでは分数も扱えるようであるが、授業内では触れられていなかったため今回は小数を使用した。
=end
