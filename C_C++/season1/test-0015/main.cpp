/*
  �v���O�������Ftest-0015
  ��������F2008�N5��12���`2008�N5��12��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F������\���v���O����
*/
#include<stdio.h>
#include<windows.h>
struct GandT{
	int a[30];
	int b;
	float c;
};
int main(){
	n:
	struct GandT aa;
	aa.a[0]=846;
	aa.a[12]=213;
	aa.a[5]=15;
	aa.b=15;
	aa.c=15.325;
	printf("%d\n%d\n%d\n",aa.a,aa.b,aa.c);
	Sleep(1000);
	goto n;
	return 0;
}