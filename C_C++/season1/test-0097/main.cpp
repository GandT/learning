/*
  �v���O�������Ftest-0097
  ����ҁF�f���s
  ��������F2008�N7��5���`2008�N7��5��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
#include<string.h>
int main()
{
	char test1[] = "�j�a�b������";
	char test2[] = "�b�o�t���D��";
	char *test3;
	test3 = strpbrk(test1,test2);
	if(test3 == NULL){
		printf("NULL!");
	} else{
	printf("%c",*test3);
	}
	return 0;
}