/*
  プログラム名：test-0124
  制作日時：2011年9月1日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ファイル出入力プログラム
*/

#include "stdio.h"

int main()
{
	FILE *fp = fopen("書き込み.txt","r");
	int moji;
	
	if(fp == NULL){
		puts("読めん");
		return 1;
	}
	
	moji = fgetc(fp);
	
	if(moji != EOF){
		printf("%c",moji);
	}
	
	fclose(fp);
	
	return 0;

}