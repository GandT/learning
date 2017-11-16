/*
  プログラム名：test-0132
  制作日時：2011年9月2日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ファイル出入力プログラム
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp = fopen("あのえーとそのあれ.wam","wb");
	__int8 data[10000];
	
	if(fp == NULL){
		puts("ふぁいるないない＾－＾－＾－＾");
		return -1;
	}
	
	for(int i = 0;i < 10000;++i)data[i] = rand();
	
	fwrite(data,1,10000,fp);
	
	fclose(fp);
}