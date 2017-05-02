#LCS（最長共通部分列）を発見するためのクラス
class Lcs
  #初期化処理
  def initialize(x,y)
    #受け取ったデータをグローバル化
    @x = x
    @y = y
    
    #動的計画法でLCSを求める
    @table = Array.new(@x.size+1) {|i| Array.new(@y.size+1,0) }
    for i in 1..@x.length
      for j in 1..@y.length
        if @x[i-1..i-1] == @y[j-1..j-1]
          @table[i][j] = @table[i-1][j-1]+1
        elsif @table[i-1][j] > @table[i][j-1]
          @table[i][j] = @table[i-1][j]
        else
          @table[i][j] = @table[i][j-1]
        end
      end
    end
  end
  
  #動的計画法で作成した表を表示
  def pr
    for i in 0..@table.length-1
      for j in 0..@table[i].length-1
        print @table[i][j]," "
      end
      print "\n"
    end
  end

  #トレースバックしてLCSを作られ方に基づいて表示
  def traceback
    x = ""
    y = ""
    i = @x.length
    j = @y.length
    while i>0 || j>0
      if i>0 && j>0 && @table[i][j] == @table[i-1][j-1]+1 && @x[i-1..i-1] == @y[j-1..j-1]
        i -= 1
        j -= 1
        x = @x[i..i] + x
        y = @y[j..j] + y
      else
        if i>0 && j>0 && @table[i][j] == @table[i-1][j-1] && @x[i-1..i-1] != @y[j-1..j-1]
          i -= 1
          j -= 1
          x = @x[i..i] + x
          y = @y[j..j] + y
        else
          if j>0 && @table[i][j] == @table[i][j-1]
            j -= 1
            x = "-" + x
            y = @y[j..j] + y
          else
            i -= 1
            x = @x[i..i] + x
            y = "-" + y
          end
        end
      end
    end
    return [x,y]
  end
  
  #動的計画法で作成した表を文字列に変換
  def to_s
    result = @x+"\n"+@y+"\n"
    for i in 0..(@table.length)-1
      for j in 0..(@table[i].length)-1
        result += @table[i][j].to_s + " "
      end
      result += "\n"
    end
    return result
  end
end
