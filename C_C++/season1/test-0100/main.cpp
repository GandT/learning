/*
  プログラム名：test-0100
  制作者：Ｇ＆Ｔ
  制作日時：2008年7月5日～2008年7月5日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
int main()
{
	char test1[3] = "票";
	printf("%s＝%c%c",test1,test1[0],test1[1]);
	return 0;
}