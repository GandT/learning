/*
  �v���O�������Ftest-0130
  ��������F2011�N9��1��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�t�@�C���o���̓v���O����
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("������ǂޓz�������Ă񂾂�n��.txt","r");
	int score1,score2,score3;
	char moji[81];
	
	if(fp == NULL){
		puts("�ǂ߂ĂȂ��O�|�O�|�O�|�O�|�O�|�O�ǂ߂ĂȂ��Ƃ��O�|�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O");
		return -1;
	}
	
	fscanf(fp,"%d%d%d%s",&score1,&score2,&score3,&moji);
	
	printf("%d\n%d\n%d\n%s",score1,score2,score3,moji);	
}