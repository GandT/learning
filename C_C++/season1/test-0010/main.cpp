/*
  プログラム名：test-0010
  制作日時：2008年5月8日～2008年5月8日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ポインタの増減テスト
*/
#include<stdio.h>
#include<windows.h>
int main(){
	int gt1;
	int *gt2=&gt1;
	g6t:
	printf("最初…%p\n",gt2);
	gt2++;
	printf("後…%p\n",gt2);
	Sleep(1000);
	goto g6t;
	return 0;
}