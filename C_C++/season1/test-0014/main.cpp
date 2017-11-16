/*
  プログラム名：test-0014
  制作日時：2008年5月10日～2008年5月10日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：文字列表示プログラム
*/
#include<stdio.h>
#include<string.h>
#include<windows.h>
int main(){
	no:
	printf("文字を入力してください→");
	char nanasi[515456];
	gets(nanasi);
	printf("\nあなたが入力した文字は%sですね？\n",nanasi);
	goto no;
	return 0;
}