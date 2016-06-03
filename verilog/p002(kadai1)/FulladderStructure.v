/*
  2016.4.15
  「全加算器」
  参考文献：池田誠(2016)「Hardware design 2016」<http://www.mos.t.u-tokyo.ac.jp/~ikeda/HWDesign/>
*/


module FullAdderStructure(x, y, cin, cout, s);
   //入力と出力の分類を行う
   input x, y, cin;
   output cout, s;
   //ワイヤー宣言
   wire   w1, w2, w3, w4, w5;

   //論理回路構成
   and a1(w1, x, y);
   and a2(w2, y, cin);
   and a3(w3, cin, x);
   or o1(w4, w1, w2);
   or o2(cout, w4, w3);
   xor x1(w5, x, y);
   xor x2(s, w5, cin);
   
endmodule
