/*
  �v���O�������Ftest-0022
  ����ҁF�f���s
  ��������F2008�N5��14���`2008�N5��24��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
int main(){
	int test1,test4;
	char test2[37]="�A�[�����h�`���R���[�g�����J�R�[�q�[";
	int* test3;
	test1=printf("%s",test2);
	test3=&test1;
	printf("��������%d\n�A�h���X��%p\n\n",test1,test3);
	while(test4==784){
		test3++;
		test4++;
	}
	test4*=478;
	printf("���ȂƂ���ɂԂ����񂾐��l��%d\n���ȂƂ���̃A�h���X��%p",*test3,test4);
	return 0;
}