/*
  �v���O�������Ftest-0127
  ��������F2011�N9��1��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�t�@�C���o���̓v���O����
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("�ǂ݂Ȃ���.txt","r");
	int c;
	
	if(fp == NULL){
		puts("������ǂ߂Ă˂����[�́I");
		return -1;
	}
	
	while(1){
	
		c = fgetc(fp);
		if(ferror(fp)){
			puts("�ǂݍ��ݒ��ɃG���[����������");
			fclose(fp);
			
			return -1;
		}
		
		if(feof(fp))break;
		
		putchar(char(c));
	}
	
	fclose(fp);
	
	return 0;
	
}