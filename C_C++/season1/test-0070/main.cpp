/*
  �v���O�������Ftest-0070
  ����ҁF�f���s
  ��������F2008�N6��9���`2008�N6��9��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
int main(){
	int test1=100;
	int *test2 = &test1;
	int **test3 = &test2;
	printf("%d\n%d\n%d\n%d\n\n",test1,*test2,*test3,**test3);
	printf("%d\n%d\n%d\n",&test1,&test2,&test3);
	return 0;
}