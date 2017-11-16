/*
  プログラム名：test-0064
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月7日～2008年6月7日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int test1=-1254,test2;
	printf("元の値…%d\n",test1);
	test2 = abs(test1);
	printf("絶対値…%d",test2);
	return 0;
}