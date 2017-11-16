/*
  プログラム名：test-0019
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月13日～2008年5月24日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<windows.h>
int main(){
	int test001,test002;
	nyo:
	int* test003=&test001;
	printf("数字入れてね→");
	scanf("%d",&test001);
	test002=test001;
	*test003=test001;
	printf("最初のtest001→%d\ntest003→%d\n",test002,test001);
	test001++;
	test003++;
	Sleep(1000);
	goto nyo;
	return 0;
}