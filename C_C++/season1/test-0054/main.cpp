/*
  プログラム名：test-0054
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月31日～2008年5月31日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#define NASU "100"
int main(){
	printf(NASU"\n");
	#undef NASU
	int NASU = 120;
	printf("%d",NASU);
	return 0;
}