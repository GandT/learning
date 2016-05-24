/*
  2016.4.15
  「全加算器」
  参考文献：池田誠(2016)「Hardware design 2016」<http://www.mos.t.u-tokyo.ac.jp/~ikeda/HWDesign/>
*/


module FullAdderFunction(x,y,cin,cout,s);
   //入出力対応関係の設定
   input x,y,cin;
   output cout,s;

   //論理式による論理回路
   assign cout = (x & y) | (x & cin) | (y & cin);
   assign s = x ^ y ^ cin;
endmodule
