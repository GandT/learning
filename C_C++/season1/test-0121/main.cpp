/*
  �v���O�������Ftest-0121
  ��������F2011�N8��19��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�����m�F�v���O����
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