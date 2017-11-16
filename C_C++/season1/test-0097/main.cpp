/*
  プログラム名：test-0097
  制作者：Ｇ＆Ｔ
  制作日時：2008年7月5日～2008年7月5日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<string.h>
int main()
{
	char test1[] = "ＫＢＣ愛狂会";
	char test2[] = "ＣＰＵ愛好会";
	char *test3;
	test3 = strpbrk(test1,test2);
	if(test3 == NULL){
		printf("NULL!");
	} else{
	printf("%c",*test3);
	}
	return 0;
}