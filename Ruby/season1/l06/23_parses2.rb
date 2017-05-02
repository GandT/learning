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
  
  #特定の定数を強制的に別の値に書き換える
  def placeConstant(c1,c2)
      #opが演算子ならばその子を辿る
      if @op.class == String
        @left.placeConstant(c1,c2)
        @right.placeConstant(c1,c2)
      
      #opが数字なら変換を施す
      else
        #C1をC2に変換
        if @op == c1
          @op = c2
        end
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
  x = ParseNodes.new("*",             # *の演算子
                   ParseNodes.new("+",ParseNodes.new(2),ParseNodes.new(3)), # *の左の式
                   ParseNodes.new("+",ParseNodes.new(3),ParseNodes.new(4)) # * の右の式
                   )
                   
  # in orderで計算結果を表示
  puts "変換前："
  print x.inorder,"=",x.value,"\n"
  
  #変換を施す
  x.placeConstant(3,5)
  
  # in orderで計算結果を表示
  puts "変換後："
  print x.inorder,"=",x.value,"\n"
end



#テスト用関数の実行
test
