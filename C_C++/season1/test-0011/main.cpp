/*
  プログラム名：test-0011
  制作日時：2008年5月8日～2008年5月8日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ポインタの増減テスト
*/
#include<stdio.h>
#include<windows.h>
long main(){
	long gt1;
	long *gt2=&gt1;
	g6t:
	printf("前…%p\n",gt2);
	gt2--;
	printf("後…%p\n",gt2);
	Sleep(100);
	goto g6t;
}