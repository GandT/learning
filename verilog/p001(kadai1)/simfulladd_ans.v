module testfulladd;
   //入力レジスタと出力ワイヤーを宣言
   wire s, co;
   reg  a, b, ci;

   //一回実行の手続きブロックを設定
   initial begin
      //数値内容を変化ごとにシミュレーションモニターに表示
      $monitor("%t 入力(x:%b,y:%b,cin:%b) -> 出力(s:%b,cout:%b)", $time, a, b, ci, s, co);

      //シミュレーション数値をそれぞれ設定　
      a <= 0; b <= 0; ci <= 0;
      #40 a <= 1; b <= 1; ci <= 0;
      #40 a <= 1; b <= 0; ci <= 1;
      #40 a <= 0; b <= 0; ci <= 1;
      #40 a <= 1; b <= 1; ci <= 1;
      #40

      //シミュレーション終了
      $finish;
   end

   //全加算器論理の実行
   FullAdderFunction add(a,b,ci,co,s);

endmodule
