/*
  �v���O�������Ftest-0054
  ����ҁF�f���s
  ��������F2008�N5��31���`2008�N5��31��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
#define NASU "100"
int main(){
	printf(NASU"\n");
	#undef NASU
	int NASU = 120;
	printf("%d",NASU);
	return 0;
}