/*
  �v���O�������Ftest-0131
  ��������F2011�N9��2��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�t�@�C���o���̓v���O����
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("���傤����.png","rb");
	__int8 b[10000];
	size_t size;
	
	if(fp == NULL){
		puts("���[���[��[�t�@�C���p�ӂ����n�������������������������I");
		return -1;
	}
	
	size = fread(b,1,5000,fp);
	
	for(size_t i = 0;i < size;++i)printf("%d�@",b[i]);
	printf("\n");
	
	fclose(fp);
	
	return 0;
}