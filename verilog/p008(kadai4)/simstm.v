module simstm;
//レジスタ・ワイヤー宣言
reg ck, rst;
wire [3:0] x;

//シミュレーション処理
initial begin
	//画像表示
	$dumpvars;
	$dumpfile("stm.vcd");

	//文字表示
	$monitor( "ck = %b, st = %b: x=%x", s.ck, s.st, s.x );

	//クロックとリセットを初期化
	ck=0; rst=0;
	#20 rst=1;
	#60 rst=0;
	#800
	  if( x == 7 )  $display("OK\n");
   $finish;
end

//クロックを数える
always #10	ck<=~ck;

//本体呼び出し	
stm	s(ck,rst,x);

endmodule
