/*
  �v���O�������Ftest-0011
  ��������F2008�N5��8���`2008�N5��8��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�|�C���^�̑����e�X�g
*/
#include<stdio.h>
#include<windows.h>
long main(){
	long gt1;
	long *gt2=&gt1;
	g6t:
	printf("�O�c%p\n",gt2);
	gt2--;
	printf("��c%p\n",gt2);
	Sleep(100);
	goto g6t;
}