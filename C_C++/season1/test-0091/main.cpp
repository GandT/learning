/*
  プログラム名：test-0091
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月21日～2008年7月5日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
int main(){
	int test1/*入力する物*/,test2/*チェック*/;
	char test3[100]/*後始末*/;

	printf("数字を入力してください\n");
	test2 = scanf("%d",&test1);
	gets(test3);
	printf("%d文字入力されました",test2);
	return 0;
}