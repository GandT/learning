/*
  プログラム名：test-0128
  制作日時：2011年9月1日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ファイル出入力プログラム
*/

#include <stdio.h>

int main()
{
	FILE *fp[2];
	char moji[101];
	
	fp[0] = fopen("読む奴.txt","r");
	
	if(fp[0] == NULL){
		puts("読めなかったんだなーこれが＾－＾－＾－＾－＾－＾－＾－＾");
		return -1;
	}
	
	fp[1] = fopen("書く奴.txt","w");
	
	if(fp[1] == NULL){
		puts("まさかの二つ目が読めなかったんですねーｗｗｗｗｗｗｗｗ");
		fclose(fp[0]);
		return -1;
	}
	
	while(1){
		
		if(fgets(moji,101,fp[0]) == NULL)break;
		
		fputs(moji,fp[1]);
	}
	
	fclose(fp[1]);
	fclose(fp[0]);
	
	return 0;
}