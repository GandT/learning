/*
  �v���O�������Ftest-0037
  ����ҁF�f���s
  ��������F2008�N5��17���`2008�N5��26��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
struct test1{
	char testing1[30];
	double testing2;
	int testing3[34];
}
int main(){
	int tester1;
	tester1=sizeof(test1);
	printf("�K���ɍ�����\���́c%dbyte\n�܁@���@���@�ȁ@�v�@���@�O�@���@���@��",tester1);
	return 0;
}
//���̃v���O�����͓��삵�܂���