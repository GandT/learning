/*
  �v���O�������Ftest-0126
  ��������F2011�N9��1��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�t�@�C���o���̓v���O����
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("moji.txt","r");
	int moji[11];
	
	if(fp == NULL){
		puts("����ȃt�@�C�����������ł���");
		return -1;
	}
	
	for(int i = 0;i < 10;++i){
		moji[i] = getc(fp);
		
		if(feof(fp))break;
	}
	
	printf("%c%c",moji[0],moji[1]);
	
	fclose(fp);
	
}