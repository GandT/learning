/*
  プログラム名：test-0099
  制作者：Ｇ＆Ｔ
  制作日時：2008年7月5日～2008年7月5日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
int main()
{
	char test1[3];
	test1[0] = 'ﾉ';
	test1[1] = 'ｼ';
	test1[2] = NULL;
	printf("%c%c＝%s",test1[0],test1[1],test1);
	return 0;
}