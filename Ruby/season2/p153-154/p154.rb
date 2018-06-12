#coding: UTF-8
=begin
  2018.6.12
  全角スペースの利用

  cf. 
=end

# 変数
　　 = "全角スペース" # 変数「　　」（全角スペース2個）
　　のんぼ　　 = 568 # 変数「　　のんぼ　　」

puts 　　
puts 　　のんぼ　　 * 12 == 12*568


# メソッド
def 　　　 # メソッド「　　　」（全角スペース3個）
    puts "第一関数"
end
def 　(input)
    puts "第二関数：#{input}"
end

　　　
　("文字列")


# クラス
# ※全角スペースは大文字扱いではないため頭に大文字をつける必要がある
class C　 # クラス「C　」
    def demand(　　　　) # 引数「　　　　」（全角スペース4個）
        puts "存在 is #{　　　　}"
    end
end

space = C　.new
space.demand("ここにいるよ")