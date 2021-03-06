module  multest;
	//レジスタ・ワイヤー宣言
	reg	[7:0]	A, B;	//入力変数
	reg	ck;		//クロック
	reg	start;
	reg	[3:0] st;
	wire	[16:0] O;
	reg	[16:0] OR;
	
	//initial文（一回だけ実行）
	initial begin
		//レジスタの初期化
		ck=0;
		start=0;
		st=0;

		//表示
		$dumpvars;
		$dumpfile("mul.vcd");
		$monitor( "%t\tA=%h, B=%h, (OUT=%h) OUT=%h", $time, A, B, O, OR );
		#1000  $finish;
	end

	//mul回路の呼び出し
	mul	MUL(A , B , O ,  ck, start,fin);

	//always文（ループ実行）
	always	#10	ck = ~ck;	//クロック処理
	always @(negedge ck) begin
		if( st == 0 ) start <= 1;
		else start <= 0;
		if( fin == 1 )begin OR <= O; A = $random; B = $random; end
		st <= st+1;
	end

endmodule
