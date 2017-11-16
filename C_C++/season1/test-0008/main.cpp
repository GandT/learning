/*
  プログラム名：test-0008
  制作日時：2008年5月8日～2008年5月8日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：scanfテスト
*/
#include <stdio.h>
int main(){
	int gt1;
	majick:
	printf("数字を入力してください\n入力した数字→");
	scanf("%d",&gt1);
	printf("あなたが入力した数字は%dですね",gt1);
	goto majick;
	return 0;
}