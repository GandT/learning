/*
  �v���O�������Ftest-0129
  ��������F2011�N9��1��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�t�@�C���o���̓v���O����
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("�ǂ߂�n��.txt","w");
	char moji[] = "���{�����^�J�[";

	if(fp == NULL){
		puts("������t�@�C�������񂾂��Ă΁[�n�[���n�[���n�[���n�[���n�[���n�[���n�[��");
		return -1;
	}
	
	fprintf(fp,"���������̖����n�����[�[�[�[�[�I�I\n%s",moji);
	
	fclose(fp);
}