/*
  プログラム名：test-0065
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月7日～2008年6月7日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<math.h>
int main(){
	double test1=15.000001
	,test2;
	printf("元々の値…%f\n",test1);
	test2 = ceil(test1);
	printf("一番近い整数…%f\n",test2);
	printf("なんだ、切り上げか……");
	return 0;
}