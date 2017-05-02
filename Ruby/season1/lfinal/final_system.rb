=begin

 ◆◆◆◆◆　Decision Graph　◆◆◆◆◆
 　Decision Graphは「議論グラフシステム」を拡張する形で作られました。
 　実行に移すか移さないかといったような意思決定をしたい事柄を決め、それに対する「支持・不支持」または「利益・不利益」、およびそれらの事
 柄に対する「支持・不支持」または「利益・不利益」を隣接リストの形で優先度数値を付加して設定することによって、結論に対する適切さ、すなわ
 ち実行するべきか否かの指標が数字によって与えられます。
 
【機能説明】
 ・1000個までのノード、すなわち意思決定に関係する事柄を登録できます
 ・addで隣接リストの形で事柄を登録します。このとき第三引数はその重要度または妥当性を示す値とします。特に妥当性の大小を気にしないような
 　場合は1や-1を設定してください
 ・conclusionで引数に指定された事柄の妥当性の度合いを数値で返します。このとき、事柄同士の間で関係性にループが生じていた場合、それらは
 　まとめて無意味な情報としてデータベースから削除されていることにご注意下さい。指定された事柄が登録されていない場合、またはループ内にあ
 　った場合は値の代わりにnilが帰ってきます
 ・conclusion2は引数に指定された事柄の妥当性の度合いを相対化した値を返します。おおむね1が基準であると考えて頂ければ問題ありません

 
=end



#Decision Graphの本体class
class DecisionGraph
    #コンストラクタ
    def initialize
        #隣接行列の初期化
        @am = Array.new(1000);         #array matrix
        for i in 0...999
            @am[i] = Array.new(1000);
        end
        
        #要素管理ハッシュ
        @ae = Hash::new;            #array elements
        @he = [];                   #hash elements
        
        #フラグの初期化
        @newto = false;
        
    end
    
    
    #データ入力
    def input()
        
    end
    
    
    #データ追加（隣接リスト）
    def add(from,to,nm)
        #データ移動
        num = nm;
        
        #fromとtoが存在しなければハッシュに登録
        if !@ae.key?(from) then
            #fromをハッシュに登録
            @ae[from] = @ae.length;
            
            #配列にfromを登録
            @he[ @ae[from] ] = from;
        end
        if !@ae.key?(to  ) then
            #toをハッシュに登録
            @ae[to  ] = @ae.length;
            
            #配列にtoを登録
            @he[ @ae[to  ] ] = to  ;
            
            #フラグをたてる
            newto = true;
        end
        
        #データを登録
        if @am[ @ae[from] ][ @ae[to] ] then
            @am[ @ae[from] ][ @ae[to] ] += num;
        else
            @am[ @ae[from] ][ @ae[to] ] = num;
            
            #初回のみ前の分も上乗せ
            if @am[ @ae[from] ][ @ae[from] ] then
                @am[ @ae[from] ][ @ae[to] ] += @am[ @ae[from] ][ @ae[from] ];
                                        num += @am[ @ae[from] ][ @ae[from] ];
            end
        end
        
        #ループチェック
        if roopcheck(@ae[from],@ae[from]) then
            #ループがあればnilに戻されるので妥当値計算はなし
            return nil;
        end
        
        #妥当値計算
        reasonability(@ae[to],num)
        
        #toの妥当値を返す
        return @am[ @ae[to] ][ @ae[to] ];
        
    end
    
    
    #startを起点とするグラフにループがないかを確認
    def roopcheck(now,start)
        #結果格納用変数
        con = false;
        
        #要素数分ループ
        for i in 0..@ae.length-1
            #道を発見した場合
            if now != i && @am[now][i] != nil then
                #ループしていたらtrue
                if i == start then
                    #ループ情報を保存
                    con = true;
                    
                    #ループしていた場合は経路と妥当値をnilに戻す
                    @am[now][i] = nil;
                    @am[now][now] = nil;
                
                #ループしていなければ調査続行
                else
                    #結論を保存
                    con = roopcheck(i,start);
                    
                    #帰ってきたものがループしていた場合はデータを消去
                    if con then
                        @am[now][i] = nil;
                        @am[now][now] = nil;
                    end
                end
            end
        end
        
        #結論を返す
        return con;
    end
    
    
    #妥当値計算
    def reasonability(start,num)            #start以降のリストの妥当値をnumで再計算する
        #初期値登録
        if @am[start][start] then
            @am[start][start] += num;
        else
            @am[start][start] = num;
        end
        
        #枝先の妥当値も変更
        for i in 0..@ae.length-1
            #道を発見した場合
            if start != i && @am[start][i] then
                print start," ",i
                puts ""
                
                #道の妥当式を計算
                @am[start][i] += num;
                
                #妥当値再計算
                reasonability(i,num);       #先にroopcheckを行いループがないことを確認した上で処理を行わないと無限ループの危険性あり
            end
        end
    end
    
    
    #妥当値を表示
    def conclusion(incident)
        #受け取ったものが存在しなければnilを返して終了
        if !@ae.key?(incident) then
            return nil;
        end
        
        #妥当値を返す
        return @am[ @ae[incident] ][ @ae[incident] ];
    end
    
    
    #標準化妥当値を表示（妥当値を全ての妥当値の平均で割ったもの
    def conclusion2(incident)
        #受け取ったものが存在しなければnilを返して終了
        if !@ae.key?(incident) then
            return nil;
        end
        
        #変数の初期値設定
        ave = 0.0;
        count = 0;
        
        #妥当値合計を求める
        for i in 0..@ae.length-1
            #nilでなければ計算に加える
            if @am[i][i] then
                ave += @am[i][i];
                count += 1;
            end
        end
        
        #妥当値平均を求める
        ave /= count;
        
        #要求されたものの妥当値を妥当値平均で割った値を返す
        return @am[ @ae[incident] ][ @ae[incident] ] / ave;
    end
    
    
    #隣接行列を表示
    def showmatrix
        for x in 0..@ae.length-1
            for y in 0..@ae.length-1
                #数値を表示（nilは代わりに/を表示）
                if @am[y][x] == nil
                    print "/ ";
                else
                    print @am[y][x]," ";
                end
                
                #一行終わったら改行
                if y == @ae.length-1 then
                    puts "";
                end
            end
        end
    end
    
    #隣接リストを表示
    def showlist
        for x in 0..@ae.length-1
            for y in 0..@ae.length-1
                #yからxへ
                if @am[y][x] then
                    print @he[y]," => ",@he[x]," : ",@am[y][x];
                    puts "";
                end
            end
        end
    end
end


puts "test"
a = DecisionGraph.new()
a.add("r2","r1",1)
a.add("r1","n5",3)
a.add("n5","n4",4)
a.add("c2","c1",-1)
a.add("c1","n4",-2)
a.add("n4","l1",0)
a.add("l1","a1",5)
a.showmatrix
a.showlist
print "x1妥当値："      #そんなものはない
p a.conclusion("x1");
print "n5妥当値：",a.conclusion("n5");
puts ""
print "n5標準化妥当値：",a.conclusion2("n5");
puts ""
print "a1妥当値：",a.conclusion("a1");
puts ""
print "a1標準化妥当値：",a.conclusion2("a1");
puts ""

=begin
【実行結果】
 test
 / / / / / / / /
 1 1 / / / / / /
 / 4 4 / / / / /
 / / 8 5 / -3 / /
 / / / / / / / /
 / / / / -1 -1 / /
 / / / 5 / / 5 /
 / / / / / / 10 10
 r2 => r1 : 1
 r1 => r1 : 1
 r1 => n5 : 4
 n5 => n5 : 4
 n5 => n4 : 8
 n4 => n4 : 5
 c1 => n4 : -3
 c2 => c1 : -1
 c1 => c1 : -1
 n4 => l1 : 5
 l1 => l1 : 5
 l1 => a1 : 10
 a1 => a1 : 10
 x1妥当値：nil
 n5妥当値：4
 n5標準化妥当値：1.0
 a1妥当値：10
 a1標準化妥当値：2.5
 

【実行結果補足】
　サイクル削除の機能についてはirbで
    irb(main):004:0> b.add("r2","r1",1)
    => 1
    irb(main):005:0> b.add("r1","r3",3)
    => 4
    irb(main):006:0> b.add("r3","r2",2)
    => nil
　の形で確認した
 
 
【参考文献】
　『「プログラム構成論」のホームページ』（http://lecture.ecc.u-tokyo.ac.jp/~yamaguch/prog-cons/2015/index.html） 最終閲覧2015.7.31
　『議論グラフシステムを作る』（http://lecture.ecc.u-tokyo.ac.jp/~yamaguch/prog-cons/2014/arg.html）　最終閲覧2015.7.31
　『Cmap』（http://cmap.ihmc.us） 最終閲覧2015.7.31
　『逆引きruby』（http://www.namaraii.com/rubytips/）最終閲覧2015.7.31
　『Rubyリファレンス』（http://ref.xaio.jp/ruby）最終閲覧2015.7.31
　『』
=end