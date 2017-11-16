/*
  プログラム名：test-0072
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月11日～2008年6月911日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：演算プログラム
*/
#include<stdio.h>
int Gtest(int g){
	int g2;
	g2 = g % 2;
	return g2;
}
int main(){
	int test1,test2;
	printf("偶数かどうか判断したい数字を入れてください");
	scanf("%d",&test1);
	test2 = Gtest(test1);
	if(test2 == 0){
		printf("入力された数字は偶数です");
	} else {
		printf("入力された数字は奇数です");
	}
	return 0;
}