/*
  �v���O�������Ftest-0050
  ����ҁF�f���s
  ��������F2008�N5��31���`2008�N5��31��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�u���b�N���Z�v���O����
*/
#include<stdio.h>
int testing1(int a){
	a++;
	a *= 12;
	return a;
}

int main(){
	int a,b;
	printf("��");
	scanf("%d",&b);
	a = testing1(b);
	printf("%d",a);
	return 0;
}