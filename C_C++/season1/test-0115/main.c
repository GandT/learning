/*
  プログラム名：test-0115
  制作者：Ｇ＆Ｔ
  制作日時：2011年8月4日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：ファイル出入力プログラム
*/

#include "stdio.h"

int main()
{
	//ファイルを開く
	FILE *file = fopen("test.txt","r");
	
	//エラーが出てたのかなどうなのかな
	if(file == NULL){
		
		printf("ファイルなんてなかった");
		
	}else {
		
		printf("ファイルが見つかりました＾−＾−＾−＾−＾−＾−＾");
		
		//だがしかし閉じてやろうではないが
		fclose(file);
		
		printf("\n\n\n\n\n\n\n\n\n\n閉じてやったぜ＾−＾−＾−＾−＾−＾−＾−＾−＾−＾−＾");
		
	}
	
	//おーわりっ
	return 0;
	
}