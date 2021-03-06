module testcount4rs;
	//ワイヤー・レジスタ宣言
	wire		[3:0] out;
	reg		ck, res;

	//シミュレーション実行内容
	initial begin
		//表示文字列
		$monitor( "%t %b %b %b", $time, ck, res, out);

		//初期化
		ck<=0;
		res<=0;

		//リセット
		#40
		res <= 1;

		//終了
		#350
		$finish;
	end

	//クロック反転
	always #10  ck <= ~ck;

	//状態機械実行
	count4rs  cnt ( out, ck, res );
endmodule
