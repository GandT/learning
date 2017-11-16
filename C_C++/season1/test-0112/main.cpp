/*
  プログラム名：test-0112
  制作者：Ｇ＆Ｔ
  制作日時：2009年8月19日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：Mixoroftの補助
*/

#include <stdio.h>
#include <math.h>
#include <windows.h>

int main(void){
	
	float teso,main2;
	
	while(1){
		
		printf("［　・∀・］　＜　数字を入力してください\n入力待ち：");
		scanf("%f",&teso);
		printf("［　・∀・］　＜　計算結果を測定しています");
		Sleep(500);
		printf("・");
		Sleep(500);
		printf("・");
		Sleep(500);
		printf("・\n");
		printf("［　・∀・］　＜　計算結果が出ました\n");
		main2 = sqrt(teso);
		printf("［　・∀・］　＜　ルート%fは%fです。\n",teso,main2);
		Sleep(2000);
		printf("［　・∀・］　＜　ご利用ありがとうございました\n\n\n");
		
		Sleep(5000);
	}
}