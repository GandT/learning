/*
  プログラム名：test-0120
  制作日時：2011年8月10日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：処理確認プログラム
*/

#include "stdio.h"

int main()
{
	__int64 number = 100000000000000;
	
	printf("%d\n",number);
	printf("%lld\n",number);
	printf("%i64d\n",number);
	printf("%I64d\n",number);
}