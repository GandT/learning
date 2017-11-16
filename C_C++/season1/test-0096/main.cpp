/*
  プログラム名：test-0096
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月28日～2008年7月25日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
int main()
{
	printf("%d",test1);
	return 0;
}

int tester()
{
	static int test1 = 100;
}
//このプログラムは起動しません