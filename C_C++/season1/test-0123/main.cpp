/*
  �v���O�������Ftest-0123
  ��������F2011�N9��1��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�t�@�C���o���̓v���O����
*/

#include "stdio.h"

int main()
{
	//�t�@�C���|�C���^
	FILE *fp;
	
	//�ǂݍ���
	fp = fopen("�ǂ݂Ȃ���.txt","r");
	
	//�ǂݍ��߂����ǂ���
	if(fp != NULL){
		
		puts("�ǂ߂�");
	}else {
		
		puts("�ǂ߂Ȃ�");
	}
	
	//�t�@�C�������
	fclose(fp);
	
	return 0;
}