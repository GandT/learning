/*
  �v���O�������Ftest-0033
  ����ҁF�f���s
  ��������F2008�N5��17���`2008�N5��26��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF��̉��Z�v���O����
*/
#include<stdio.h>
#include<windows.h>
int main(){
	int test1;
	g6t:
	printf("�������͂��Ȃ�����");
	scanf("%d",&test1);
	printf("�ŏ��̐��c%d\n",test1);
	test1*=24;
	test1--;
	test1+=39;
	test1*test1;
	test1++;
	test1%=487;
	test1-=34;
	test1+=65;
	printf("��");
	Sleep(1000);
	printf("�Z");
	Sleep(1000);
	printf("��");
	Sleep(1000);
	printf("�c");
	Sleep(1000);
	printf("�c");
	Sleep(1000);
	printf("�c\n\n\n");
	Sleep(1000);
	printf("���Z��̐��c%d\n",test1);
	Sleep(5000);
	printf("���Ă�����x");
	goto g6t;
	return 0;
}