/*
  �v���O�������Ftest-0043
  ����ҁF�f���s
  ��������F2008�N5��28���`2008�N5��28��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�������݃v���O����
*/
#include<stdio.h>
#define size 1000
int main(int argc, char *argv[]){
	FILE *test1;//�t�@�C���|�C���^
	char test2[size];//�������ނ���
	int test3;//for�J�E���g
	test1 = fopen(argv[1], "wt");
	if(test1 == NULL){
		return -1;
	}
	for(test3 = 0;test3 < 5;test3++){
		printf("%d�s�ڂɏ������ނ��́�",test3+1);
		scanf("%s",test2);
		fputs(test2,test1);
		fputs("\n",test1);
	}
	fclose(test1);
	return 0;
}