/*
  プログラム名：test-0125
  制作日時：2011年9月1日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ファイル出入力プログラム
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("文字列.txt","w");
	char moji[201];
	
	puts("文字列を入力して下さい");
	
	fgets(moji,201,stdin);
	
	if(fp == NULL){
		puts("あっ、ごっめーんｗｗｗｗｗ実はファイル開けて無かったわーｗｗｗｗｗｗｗｗってことで強制終了するけど怒らないでねーｗｗｗｗｗｗｗｗｗｗｗｗ");
	}
	
	for(int i = 0;moji[i];++i)fputc(moji[i],fp);
	
	fclose(fp);
	
	return 0;
	
	
}