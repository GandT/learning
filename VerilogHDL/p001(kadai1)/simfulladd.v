/*
  2016.4.15
  「全加算器」
  参考文献：池田誠(2016)「Hardware design 2016」<http://www.mos.t.u-tokyo.ac.jp/~ikeda/HWDesign/>
*/


module testfulladd;
   //入力レジスタと出力ワイヤーを宣言
   wire[0:0] s, co;
   reg [0:0] a, b, ci;

   //一回実行の手続きブロックを設定
   initial begin
      //数値内容を変化ごとにシミュレーションモニターに表示
      $monitor("%t %b + %b + %b = %b cout:%b", $time, a, b, ci, s, co);

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
   FullAdderFunction f1(a,b,ci,co,s);

endmodule
