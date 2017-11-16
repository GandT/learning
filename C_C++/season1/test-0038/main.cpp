/*
  プログラム名：test-0038
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月18日～2008年5月26日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<windows.h>
#include<time.h>
long main(){
	long testa=0;
	srand((unsigned)time(NULL));
	testa=rand()%1001;
	while(testa!=1000){
		printf("%d\n",testa);
		testa++;
		Sleep(100);
	}
	printf("はい、終わり！");
	Sleep(2000);
	return 0;
}