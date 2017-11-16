/*
  プログラム名：test-0105
  制作者：Ｇ＆Ｔ
  制作日時：2008年7月16日～2008年7月16日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include"DxLib.h"
int main()
{
	int test1;
	__int64 test2;
	test1 = sizeof(test2);
	printf("__int64は%dbyteなのか？",test1);
	return 0;
}