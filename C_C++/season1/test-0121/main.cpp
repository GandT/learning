/*
  プログラム名：test-0121
  制作日時：2011年8月19日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：処理確認プログラム
*/

#include "stdio.h"

class A;
class B;


class A
{
	
	public:
	
	A(int a,int b){test1 = a;test2 = b;}
	int test1;
	int test2;
	
	static B *test3;
};

B *A::test3 = NULL;

class B
	:public A
{
	B():A(0,0){test4 = 0;}
	int test4;
};





int main()
{
	
}