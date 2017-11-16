/*
  プログラム名：test-0127
  制作日時：2011年9月1日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ファイル出入力プログラム
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("読みなさい.txt","r");
	int c;
	
	if(fp == NULL){
		puts("だから読めてねえっつーの！");
		return -1;
	}
	
	while(1){
	
		c = fgetc(fp);
		if(ferror(fp)){
			puts("読み込み中にエラーが発生した");
			fclose(fp);
			
			return -1;
		}
		
		if(feof(fp))break;
		
		putchar(char(c));
	}
	
	fclose(fp);
	
	return 0;
	
}