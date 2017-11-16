/*
  プログラム名：test-0122
  制作日時：2011年8月20日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：処理確認プログラム
*/

#include "stdio.h"

#define Null(X)		if(X == NULL)


void main()
{
	int a = 0;
	int *p = NULL;
	
	//p = &a;
	
	Null(p)puts("ぬるぽ"); else puts("ガッ！");
}