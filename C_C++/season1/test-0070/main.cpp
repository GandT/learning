/*
  プログラム名：test-0070
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月9日～2008年6月9日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
int main(){
	int test1=100;
	int *test2 = &test1;
	int **test3 = &test2;
	printf("%d\n%d\n%d\n%d\n\n",test1,*test2,*test3,**test3);
	printf("%d\n%d\n%d\n",&test1,&test2,&test3);
	return 0;
}