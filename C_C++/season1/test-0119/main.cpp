/*
  プログラム名：test-0119
  制作者：Ｇ＆Ｔ
  制作日時：2011年8月4日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：ファイル出入力プログラム
*/

#include "stdio.h"

#define efor(X)			for(int i = 0;i < X;++i)

int main()
{
	char mojis[201];
	
	//文字列読み込みなの
	printf("文字列をしちゅ、しゅつろ、しゅつりょくして欲しいのです＞＜\n……って間違えた！　にゅうりょく、入力なのですっ！！\n：");
	fgets(mojis,sizeof(mojis),stdin);
	
	//ふぁいるーーーーーーー
	FILE *file = fopen("びぇぇ.txt","w");
	
	//ちぇっくなのでしゅりゅ
	if(file == NULL)
	{
		printf("ふぁ、ふぁいりゅが見つからなかったのです……");
	}
}