/*
  2016.7.8
  「全加算器 / シミュレーター実験」
*/


module fulladder(x, y, cin, cout, s);
   //入力と出力の分類を行う
   input x, y, cin;
   output cout, s;
   //ワイヤー宣言
   wire   w1, w2, w3, w4, w5;

   //論理回路構成
   and(w1, x, y);
   and(w2, y, cin);
   and(w3, cin, x);
   or (w4, w1, w2);
   or (cout, w4, w3);
   xor(w5, x, y);
   xor(s, w5, cin);
endmodule


module sim;
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
   fulladder f1(a,b,ci,co,s);

endmodule
