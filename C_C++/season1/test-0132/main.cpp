/*
  �v���O�������Ftest-0132
  ��������F2011�N9��2��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�t�@�C���o���̓v���O����
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp = fopen("���̂��[�Ƃ��̂���.wam","wb");
	__int8 data[10000];
	
	if(fp == NULL){
		puts("�ӂ�����Ȃ��Ȃ��O�|�O�|�O�|�O");
		return -1;
	}
	
	for(int i = 0;i < 10000;++i)data[i] = rand();
	
	fwrite(data,1,10000,fp);
	
	fclose(fp);
}