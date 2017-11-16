/*
  プログラム名：test-0102
  制作者：Ｇ＆Ｔ
  制作日時：2008年7月5日～2008年7月5日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<ctype.h>
int main()
{
	char test1;
	int test2;
	printf("半角文字を入力してください→");
	scanf("%c",&test1);
	test1 = isalnum(test1);
	if(test1 != 0){
		printf("あなたが入力した文字は英数字です");
	} else {
		printf("あなたが入力した文字は英数字ではありません");
	}
	return 0;
}