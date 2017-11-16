/*
  プログラム名：test-0044
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月29日～2008年5月29日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：書き込みプログラム
*/
#include<stdio.h>
#include<string.h>
unsigned long main(){
	char test1[] = "ぬるぽっとさいどの味噌寿司";
	size_t test2;
	printf("%s",test1);
	test2 = strlen(test1);
	printf("%d",test2);
	return 0;
}