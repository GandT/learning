/*
  プログラム名：test-0055
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月31日～2008年5月31日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：ダンププログラム
*/
#include<stdio.h>
#define SIZE 200
int main(int argc, char* argv[]){
	FILE *fp_dmp;//ダンプ用ファイルポインタ
	int file_size;//ファイルサイズ
	int buf;//データ置き場
	FILE *fp_result;//書き込み用ファイルポインタ
	char line_buf[SIZE];//メモ帳への書き込み
	file_size = 0;
	fp_dmp = fopen("th07.exe","rb");
	if(fp_dmp==NULL){
		return -1;	
	}
	fp_result = fopen("data.txt","wt");
	if(fp_result==NULL)return -1;
	while(1){
		buf = fgetc(fp_dmp);
		if(buf == EOF){
			break;
		}
		++file_size;
		printf("%02x",buf);
		sprintf(line_buf,"0x%x ",buf);
//		line_buf = buf;
		fputs(line_buf,fp_result);
		if(file_size % 16 == 0){
			printf("\n");
			fputs("\n",fp_result);
		}
	}
	fclose(fp_result);
	fclose(fp_dmp);
	return 0;
}
