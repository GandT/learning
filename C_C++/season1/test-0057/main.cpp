/*
  �v���O�������Ftest-0057
  ����ҁF�f���s
  ��������F2008�N6��2���`2008�N6��2��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
#include<string.h>
int main(){
	char test1[100]="�͂��͂��͂ɂȂ���";
	char test2[]="�k���|�b�g";
	strcat(test1,test2);
	printf("%s,%d",test1,test2);
	return 0;
}