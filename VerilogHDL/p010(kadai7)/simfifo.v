
module top;
	//レジスタ・ワイヤー宣言
   	reg[7:0] Din;		//入力
	wire [7:0] Dout;	//出力
	reg ck, rst, Wen, Ren, flag;	//クロック・リセット・ライトイネーブル・リードイネーブル・何らかのフラグ
	wire Fempty, Ffull;	//空フラグ / 満フラグ

	//キューを呼び出す
	fifo fifo( Din, Dout, Wen, Ren, rst, ck, Fempty, Ffull );

	//初期化
	initial begin
		ck = 0;		//クロック初期化
		rst = 1;	//リセットを行う
		$dumpfile( "fifo.vcd" );	//シミュレータ出力
		$dumpvars;
		#20 rst = 0;
		#50 rst = 1;
		#10000 
		$finish;
	end

	//テストベンチ
	always @(negedge ck)begin
		flag = $random;
		if( flag == 1 )begin
			Wen <= 1;
			Ren <= 0;
			Din = $random;
		end else 
		begin
			Wen <= 0;
			Ren <= 1;
		end
	end

	always #10 ck <= ~ck;

endmodule
