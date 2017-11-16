/*
  プログラム名：test-0131
  制作日時：2011年9月2日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：ファイル出入力プログラム
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("きょうっか.png","rb");
	__int8 b[10000];
	size_t size;
	
	if(fp == NULL){
		puts("だーかーらーファイル用意しろや馬鹿あああああああああああ！");
		return -1;
	}
	
	size = fread(b,1,5000,fp);
	
	for(size_t i = 0;i < size;++i)printf("%d　",b[i]);
	printf("\n");
	
	fclose(fp);
	
	return 0;
}