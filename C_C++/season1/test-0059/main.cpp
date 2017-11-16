/*
  プログラム名：test-0059
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月4日～2008年6月4日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<string.h>
size_t main(){
	int test3;
	char test1[]="浅賀や公園";
	char test2[]="狂気と混乱の機械魔獣";
	test3 = strcmp(test1,test2);
	printf("%d",test3);
	return 0;
}