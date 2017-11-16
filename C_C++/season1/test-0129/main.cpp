/*
  プログラム名：test-0129
  制作日時：2011年9月1日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ファイル出入力プログラム
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("読めよ馬鹿.txt","w");
	char moji[] = "日本レンタカー";

	if(fp == NULL){
		puts("だからファイル無いんだってばー馬ー鹿馬ー鹿馬ー鹿馬ー鹿馬ー鹿馬ー鹿馬ー鹿");
		return -1;
	}
	
	fprintf(fp,"落ち着きの無い馬鹿がーーーーー！！\n%s",moji);
	
	fclose(fp);
}