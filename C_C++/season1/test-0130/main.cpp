/*
  プログラム名：test-0130
  制作日時：2011年9月1日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ファイル出入力プログラム
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("だから読む奴だっつってんだろ馬鹿.txt","r");
	int score1,score2,score3;
	char moji[81];
	
	if(fp == NULL){
		puts("読めてない＾−＾−＾−＾−＾−＾読めてないとか＾−＾−＾−＾−＾−＾−＾−＾−＾−＾");
		return -1;
	}
	
	fscanf(fp,"%d%d%d%s",&score1,&score2,&score3,&moji);
	
	printf("%d\n%d\n%d\n%s",score1,score2,score3,moji);	
}