/*
  �v���O�������Ftest-0125
  ��������F2011�N9��1��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�t�@�C���o���̓v���O����
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("������.txt","w");
	char moji[201];
	
	puts("���������͂��ĉ�����");
	
	fgets(moji,201,stdin);
	
	if(fp == NULL){
		puts("�����A�����߁[�񂗂����������̓t�@�C���J���Ė���������[�������������������Ă��Ƃŋ����I�����邯�Ǔ{��Ȃ��łˁ[������������������������");
	}
	
	for(int i = 0;moji[i];++i)fputc(moji[i],fp);
	
	fclose(fp);
	
	return 0;
	
	
}