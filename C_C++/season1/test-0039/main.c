/*
  プログラム名：test-0039
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月18日～2008年5月26日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<windows.h>
#define asa 215
int main(){
	int testa=0;
	do{
		printf("鏞鰀鍗蕓罇燁燾獷渹涇﨟薰蘒鰀黑\n");
		testa++;
		Sleep(10);
	}while(testa!=asa);
	printf("\n\n\nこれ何語？\nってか、自分で作っておきながら………");
	return 0;
}