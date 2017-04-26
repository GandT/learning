/*
  2016.7.8
  「多数決」
  参考文献：坂井修一(2009)『実践 コンピュータアーキテクチャ』コロナ社 p.28
*/



module majority(A, B, C, MAJO);
	//引数の入出力設定
	input A, B, C;
	output MAJO;
	
	//ネット宣言
	wire AB, BC, CD;

	//1が2つあればAB,BC,CAのいずれかが1になる
	and(AB, A, B);
	and(BC, B, C);
	and(CA, C, A);
	or(MAJO, AB, BC, CA);
endmodule


module sim;
	//レジスタ・ワイヤ宣言
	reg a, b, c;
	wire mj;

	//シミュレーション
	initial begin 
		//初期化
		a <= 0; b <= 0; c <= 0;

		//内容表示
		$monitor("%t (%d, %d, %d) -> %d", $time, a, b, c, mj);

		//数値変更
		#10 a <= 0; b <= 1; c <= 0;
		#10 a <= 1; b <= 1; c <= 0;
		#10 a <= 1; b <= 0; c <= 0;
		#10 a <= 0; b <= 1; c <= 1;
		#10 a <= 1; b <= 1; c <= 1;
		#10 $finish;
	end

	//回路実行
	majority m(a, b, c, mj);
	
endmodule



