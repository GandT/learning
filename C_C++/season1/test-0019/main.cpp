/*
  �v���O�������Ftest-0019
  ����ҁF�f���s
  ��������F2008�N5��13���`2008�N5��24��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
#include<windows.h>
int main(){
	int test001,test002;
	nyo:
	int* test003=&test001;
	printf("��������Ăˁ�");
	scanf("%d",&test001);
	test002=test001;
	*test003=test001;
	printf("�ŏ���test001��%d\ntest003��%d\n",test002,test001);
	test001++;
	test003++;
	Sleep(1000);
	goto nyo;
	return 0;
}