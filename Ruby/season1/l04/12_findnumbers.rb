#load("piRead.rb")
load("00_sman.rb")


#数列の中から数列を探し出す関数
def findNumbers(field,check)
    #探す内容を記録したSMAクラスの作成
    numbers = Sma.new(check);
    
    #SMAによる配列サーチ
    numbers.match(field);
end


#0から9までが連なった数列を円周率の中から探し出す
#findNumbers([0,0,1,0,1,2,3,4,5,6,0,1,2,3,4,5,6,7,8,9,0,0,1,2],[0,1,2,3,4,5,6,7,8,9])
findNumbers(piRead,[0,1,2,3,4,5,6,7,8,9])


=begin
　ftp://pi.super-computing.org/pub/pi10m/pi10m.ascii.01of10 にアクセスできず円周率のデータをダウンロードすることができなかったため、
コメントアウトされている行でデバッグしました。
=end
