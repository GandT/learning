/*
  �v���O�������Ftest-0024
  ����ҁF�f���s
  ��������F2008�N5��15���`2008�N5��24��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
#include<time.h>
#include<windows.h>
int main(){
	int test1;
	test2:
	test1=clock();
	printf("���ݎ����c%d\n",test1);
	Sleep(1000);
	goto test2;
	return 0;
}