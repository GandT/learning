/*
  �v���O�������Ftest-0124
  ��������F2011�N9��1��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�t�@�C���o���̓v���O����
*/

#include "stdio.h"

int main()
{
	FILE *fp = fopen("��������.txt","r");
	int moji;
	
	if(fp == NULL){
		puts("�ǂ߂�");
		return 1;
	}
	
	moji = fgetc(fp);
	
	if(moji != EOF){
		printf("%c",moji);
	}
	
	fclose(fp);
	
	return 0;

}