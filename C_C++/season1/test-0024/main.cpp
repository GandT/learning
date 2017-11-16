/*
  プログラム名：test-0024
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月15日～2008年5月24日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<time.h>
#include<windows.h>
int main(){
	int test1;
	test2:
	test1=clock();
	printf("現在時刻…%d\n",test1);
	Sleep(1000);
	goto test2;
	return 0;
}