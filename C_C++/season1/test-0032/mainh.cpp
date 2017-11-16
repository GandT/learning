/*
  プログラム名：test-0032
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月17日～2008年5月26日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
int main(){
	char test1[21356];
	short test2;
	printf("なんか入力しろ！→");
	scanf("%s",test1);
	test2=printf("\n入力された物…%s\n",test1);
	printf("文字数…%dbyte",test2);
	return 0;
}