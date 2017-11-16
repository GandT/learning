/*
  プログラム名：test-0114
  制作者：Ｇ＆Ｔ
  制作日時：2010年3月22日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：大蛇教育用テストプログラム
*/

#include <stdio.h>

int av(int x,int y)
{
	int z = (x + y) / 2;
	
	return z;
}


int main(void)
{
	int a = 0;
	
	a = av(3,5);
	
	printf("%d",a);


}