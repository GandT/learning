/*
  プログラム名：test-0037
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月17日～2008年5月26日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
struct test1{
	char testing1[30];
	double testing2;
	int testing3[34];
}
int main(){
	int tester1;
	tester1=sizeof(test1);
	printf("適当に作った構造体…%dbyte\nま　た　妙　な　プ　ロ　グ　ラ　ム　を",tester1);
	return 0;
}
//このプログラムは動作しません