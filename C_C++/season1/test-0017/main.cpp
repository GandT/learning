/*
  �v���O�������Ftest-0016
  ��������F2008�N5��12���`2008�N5��12��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F������\���v���O����
*/
#include<stdio.h>
int main(){
	int test1=132,test2=0;
	int* test3;
	test3=&test1;
	printf("���g�c%d\n�A�h���X�c%p\n\n\n",*test3,test3);
	while(test2!=100){
	  test3++;
	  test2++;
	  };
	  printf("���g�c%d\n�A�h���X�c%p\n\n\n\n�܂��A������܂��̌��ʂł���",*test3,test3);
	  return 0;
}