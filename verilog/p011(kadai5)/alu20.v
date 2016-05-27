//算術演算器
module  alu(A,B,O,CTR,ck);
	//入出力の割り当て
	input	[7:0]	A, B;	//入力値
	input	[3:0]	CTR;	//ALU演算指定
	input	ck;				//クロック
	output	[7:0] O;		//出力

	//レジスタ宣言
	reg	[7:0]	INA, INB, O;	//入力レジスタ×2 / 出力レジスタ / 出力レジスタ
	reg	[3:0]	C;

	always @(posedge ck) begin
		C <= CTR;	
		INA <= A;
		INB <= B;
		O <= 0;
		case  (C)
		'b0000 : O <= INA + INB;	//加算
		'b0001 : O <= INA - INB;	//減算
		'b1000 : O <= INA & INB;	//論理積（ビットごと）
		'b1001 : O <= INA | INB;	//論理和（ビットごと）
		'b1010 : O <= INA ^ INB;	//排他的論理和（ビットごと）
		'b1011 : O <= ~INA;			//反転
		'b1100 : O <= INA>>1;		//右シフト
		'b1101 : O <= INA<<1;		//左シフト
		'b1110 : O <= {INA[0], INA[7:1]};	//右循環
		'b1111 : O <= {INA[6:0], INA[7]};	//左循環
		endcase
	end

endmodule
