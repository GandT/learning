load("00_lcs.rb")

#ファイルをあける
f = open("TNT.txt")

#文章を読み込む
while line = f.gets do
    #改行文字を消す（windowsエンコーディングなので二文字削除）
    txt = line.chomp.chomp
    
    #LCSを計算
    dif = Lcs.new("To be or not to be",txt);
    
    #差を表示
    tb = dif.traceback
    print(tb[0],"\n");
    print(tb[1],"\n");
	print "\n"
end


#ファイルを閉じる
f.close



#以下コメント
=begin
【実行結果】
To be or not t-o b-e
To be or no- t otboe

To be or not to be-
TO be or not to-be 

To be o-r- n-ot- -to b-e
to be-o ro nmotp it--bio

To be- or not to- be
TO bei or not tot be

To be- -or not to be
To ber nor nor to be

To be or not to be
To be or not to be

To be or not to be-
To-be or nor to beo

To be- o-r no-t to be
To bew oar noat to be

To be or not to be
To be or not to ba

To be o-r not to be
To be oar not to be

To be- or not to be
To ber or not to be

To be or not to be
To be or not to be

To be- or not to be
To beo or not to be

To be- or not to be
T9 beo or not to  o

To be or not to be-
To be or not to be 


【分析】
　-記号が主に一行目（正しい文）に対してのみ現れることから、誤タイプの場合は基本的に入力のし過ぎであることがわかる。
特に多くの-が入ってしまっているところではキーボードの隣の文字を併せて入力してしまったためだと見て取れる。
　一方、ごくまれに二行目（入力文）に-が現れることがあるが、これは単語の区切りであるスペースキーの討ち漏らしが原因で
あると考えられる。
　入力文字数に違いがない場合でも、隣のキーを打ってしまっている場合や最初のスペースキーが押しっぱなしになっているこ
とによるタイプミスもみられる。

=end