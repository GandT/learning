/*
  �v���O�������Ftest-0010
  ��������F2008�N5��8���`2008�N5��8��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�|�C���^�̑����e�X�g
*/
#include<stdio.h>
#include<windows.h>
int main(){
	int gt1;
	int *gt2=&gt1;
	g6t:
	printf("�ŏ��c%p\n",gt2);
	gt2++;
	printf("��c%p\n",gt2);
	Sleep(1000);
	goto g6t;
	return 0;
}