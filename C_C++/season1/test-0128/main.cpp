/*
  �v���O�������Ftest-0128
  ��������F2011�N9��1��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�t�@�C���o���̓v���O����
*/

#include <stdio.h>

int main()
{
	FILE *fp[2];
	char moji[101];
	
	fp[0] = fopen("�ǂޓz.txt","r");
	
	if(fp[0] == NULL){
		puts("�ǂ߂Ȃ������񂾂ȁ[���ꂪ�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O");
		return -1;
	}
	
	fp[1] = fopen("�����z.txt","w");
	
	if(fp[1] == NULL){
		puts("�܂����̓�ڂ��ǂ߂Ȃ�������ł��ˁ[����������������");
		fclose(fp[0]);
		return -1;
	}
	
	while(1){
		
		if(fgets(moji,101,fp[0]) == NULL)break;
		
		fputs(moji,fp[1]);
	}
	
	fclose(fp[1]);
	fclose(fp[0]);
	
	return 0;
}