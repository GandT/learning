/*
  プログラム名：test-0067
  制作者：矢沢久雄
  制作日時：2008年6月9日～2008年6月9日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：データ読み書きプログラム
*/
#include<stdio.h>
#define FILE_NAME "Gakusei.dat"
int main(int argc, char *argv[]){
	FILE *fp;//ファイルポインタ
	char shimei[80];//氏名
	int tokuten;//得点
	long offset;//ファイルの読み書き位置
	int i;//ループカウンター
	
	//書き込み
	
	fp = fopen(FILE_NAME,"wb");
	if(fp == NULL){
		//異常終了
		return 0;
	}
	printf("書き込み\n");
	for(i = 0;i < 3;++i){
		//データの入力
		printf("氏名：");
		scanf("%s",shimei);
		printf("得点：");
		scanf("%d",&tokuten);
		//氏名を書き込む
		offset = (sizeof(shimei) + sizeof(tokuten) * i);
		fseek(fp,offset,0);
		fwrite(shimei,sizeof(shimei),1,fp);
		//得点を書き込む
		offset += sizeof(shimei);
		fseek(fp,offset,0);
		fwrite(&tokuten,sizeof(tokuten),1,fp);
	}
	fclose(fp);
}