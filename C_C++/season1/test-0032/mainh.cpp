/*
  �v���O�������Ftest-0032
  ����ҁF�f���s
  ��������F2008�N5��17���`2008�N5��26��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
int main(){
	char test1[21356];
	short test2;
	printf("�Ȃ񂩓��͂���I��");
	scanf("%s",test1);
	test2=printf("\n���͂��ꂽ���c%s\n",test1);
	printf("�������c%dbyte",test2);
	return 0;
}