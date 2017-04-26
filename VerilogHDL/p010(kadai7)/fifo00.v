//キュー
module fifo ( Din, Dout, Wen, Ren, rst, ck, Fempty, Ffull );
	//入出力端子宣言
	input [7:0] Din;		//入力端子
	output [7:0] Dout;		//出力端子
	input Wen, Ren;			//ライトイネーブル / リードイネーブル
	input rst, ck;			//リセットフラグ / クロック
	output Fempty, Ffull;	//空フラグ出力 / 満フラグ出力

	//レジスタ・ワイヤー宣言
	reg  [7:0] FMEM[0:15];		//キューメモリ
	reg  [3:0] Wptr, Rptr;		//書き込みデータ / 読み出しデータ
	reg  Fempty, Ffull;			//空フラグ / 満フラグ
	reg  [7:0] obuf;			//出力レジスタ
	wire [3:0] NWptr, NRptr;	//次ステップ書き込み・読み出しデータ線

	//ワイヤー接続
	assign Dout = obuf;			//出力端子->出力
	assign NWptr = Wptr + 1;	//ライトポインタ
	assign NRptr = Rptr + 1;	//リードポインタ
	
	//ワイヤー宣言
	wire  [7:0]  f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15;	//キューの要素数（16本）

	//キューのデータ保存用レジスタにワイヤーをつなぐ
	assign f0 = FMEM[0];
	assign f1 = FMEM[1];
	assign f2 = FMEM[2];
	assign f3 = FMEM[3];
	assign f4 = FMEM[4];
	assign f5 = FMEM[5];
	assign f6 = FMEM[6];
	assign f7 = FMEM[7];
	assign f8 = FMEM[8];
	assign f9 = FMEM[9];
	assign f10 = FMEM[10];
	assign f11 = FMEM[11];
	assign f12 = FMEM[12];
	assign f13 = FMEM[13];
	assign f14 = FMEM[14];
	assign f15 = FMEM[15];

	//初期化
	initial begin
		Wptr <= 0;
		Rptr <= 0;
		Fempty <= 1;
		Ffull <= 0;
	end

	//組み合わせ回路
	always @(posedge ck) begin
		//初期化処理
	    if( !rst ) begin
			Wptr <= 0;
			Fempty <= 1;
	    end else

		//通常処理		
		begin
			//読み出し可能時
			if( Ren == 1 && Fempty != 1 ) begin
				//デキュー
				obuf <= FMEM[Rptr];
				Rptr <= NRptr;

				//満フラグを倒す
				Ffull <= 0;

				//空フラグ操作
				if( NRptr == Wptr ) Fempty <= 1;
				else Fempty <= 0;
			end
			//書き込み可能時
			if( Wen == 1 && Ffull != 1 ) begin
				//エンキュー
				FMEM[Wptr] <= Din;
				Wptr <= Wptr + 1;

				//空フラグを倒す
				Fempty <= 0;

				//満フラグ操作
				if( NWptr == Rptr ) Ffull <= 1;
				else Ffull <= 0;
		
			end
	    end
	end
endmodule
