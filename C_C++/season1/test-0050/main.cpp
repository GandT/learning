/*
  プログラム名：test-0050
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月31日～2008年5月31日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：ブラック演算プログラム
*/
#include<stdio.h>
int testing1(int a){
	a++;
	a *= 12;
	return a;
}

int main(){
	int a,b;
	printf("→");
	scanf("%d",&b);
	a = testing1(b);
	printf("%d",a);
	return 0;
}