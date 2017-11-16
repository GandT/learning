/*
  プログラム名：test-0043
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月28日～2008年5月28日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：書き込みプログラム
*/
#include<stdio.h>
#define size 1000
int main(int argc, char *argv[]){
	FILE *test1;//ファイルポインタ
	char test2[size];//書き込むもの
	int test3;//forカウント
	test1 = fopen(argv[1], "wt");
	if(test1 == NULL){
		return -1;
	}
	for(test3 = 0;test3 < 5;test3++){
		printf("%d行目に書き込むもの→",test3+1);
		scanf("%s",test2);
		fputs(test2,test1);
		fputs("\n",test1);
	}
	fclose(test1);
	return 0;
}