/*
  �v���O�������Ftest-0102
  ����ҁF�f���s
  ��������F2008�N7��5���`2008�N7��5��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
#include<ctype.h>
int main()
{
	char test1;
	int test2;
	printf("���p��������͂��Ă���������");
	scanf("%c",&test1);
	test1 = isalnum(test1);
	if(test1 != 0){
		printf("���Ȃ������͂��������͉p�����ł�");
	} else {
		printf("���Ȃ������͂��������͉p�����ł͂���܂���");
	}
	return 0;
}