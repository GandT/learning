/*
  プログラム名：test-0001
  制作日時：2008年5月1日～2008年5月1日
  制作：Ｇ＆Ｔ
  制作ソフト：メモ帳,ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：メモリ破壊プログラム
*/
#include <stdio.h>
int main(){
	char g='G',and='&',t='T';
	printf("%c",g);
	printf("%c",and);
	printf("%c",t);
	return 0;
}