/*
  プログラム名：test-0123
  制作日時：2011年9月1日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ファイル出入力プログラム
*/

#include "stdio.h"

int main()
{
	//ファイルポインタ
	FILE *fp;
	
	//読み込み
	fp = fopen("読みなさい.txt","r");
	
	//読み込めたかどうか
	if(fp != NULL){
		
		puts("読めた");
	}else {
		
		puts("読めない");
	}
	
	//ファイルを閉じる
	fclose(fp);
	
	return 0;
}