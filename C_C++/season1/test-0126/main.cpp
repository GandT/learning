/*
  プログラム名：test-0126
  制作日時：2011年9月1日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ファイル出入力プログラム
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("moji.txt","r");
	int moji[11];
	
	if(fp == NULL){
		puts("そんなファイル無かったですし");
		return -1;
	}
	
	for(int i = 0;i < 10;++i){
		moji[i] = getc(fp);
		
		if(feof(fp))break;
	}
	
	printf("%c%c",moji[0],moji[1]);
	
	fclose(fp);
	
}